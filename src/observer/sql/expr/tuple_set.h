#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "util/util.h"
#include "util/comparator.h"
#include "util/typecast.h"
#include "sql/expr/tuple.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

struct HashFunc{
	template<typename T, typename U>
	size_t operator()(const std::pair<T, U>& p) const {
		return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
	}
};
struct EqualTo {
	template<typename T, typename U>
	bool operator ()(const std::pair<T, U>& p1, const std::pair<T, U>& p2) const {
		return p1.first == p2.first && p1.second == p2.second;
	}
};

typedef std::unordered_map<std::pair<std::string, std::string>, int, HashFunc, EqualTo> HashLocation;

void speces_copy(const std::vector<TupleCellSpec*> &, std::vector<TupleCellSpec*> &, HashLocation &);
bool tuple_cell_comp(TupleCell &, TupleCell &, CompOp);

class TupleSet
{
public:
  TupleSet() = default;
  ~TupleSet() {
    for (auto iter : speces_) {
      if (iter != nullptr) {
        delete iter;
        iter = nullptr;
      }
    }
    speces_.clear();
    tuples_.clear();
  }

public:
  const std::vector<TupleCellSpec*> &speces() const { return speces_; }
  const std::vector<MagicTuple> &tuples() const { return tuples_; }

public:
  static RC inner_join(const TupleSet *p, const TupleSet *q, TupleSet *result, const FilterStmt *filter) {
    RC rc = RC::SUCCESS;
    if (q->tuples().size() > p->tuples().size()) { // 大表作为驱动表
      const TupleSet *tmp = p;
      p = q;
      q = tmp;
    }
    // 初始化表头
    static std::vector<TupleCellSpec*> speces;
    static HashLocation field_location; // hash表用来定位字段位置
    speces.clear();
    field_location.clear();

    const int spec_len = p->speces().size() + q->speces().size();
  
    speces_copy(p->speces(), speces, field_location);
    speces_copy(q->speces(), speces, field_location);
    assert(spec_len == speces.size());
    result->set_speces(speces);
    // for (int j = 0 ; j < result->speces().size() ; ++ j) {
    //   std::cout << dynamic_cast<FieldExpr*>(result->speces()[j]->expression())->table_name() << " - " << dynamic_cast<FieldExpr*>(result->speces()[j]->expression())->field_name() << std::endl;
    // }

    const int p_spec_len = p->speces().size();
    const int q_spec_len = q->speces().size();

    std::vector<MagicTuple> tuples;
    for (auto p_tuple : p->tuples()) {
      for (auto q_tuple : q->tuples()) {
        bool save = true;
        for (auto filter : filter->filter_units()) {
          if (filter->left()->type() == ExprType::VALUE || filter->right()->type() == ExprType::VALUE) continue;
          FieldExpr *left = static_cast<FieldExpr*>(filter->left());
          FieldExpr *right = static_cast<FieldExpr*>(filter->right());
          if (field_location.count(std::make_pair(std::string(left->table_name()), std::string(left->field_name()))) == 0) continue;
          if (field_location.count(std::make_pair(std::string(right->table_name()), std::string(right->field_name()))) == 0) continue;
          
          const int left_cell_index = field_location[std::make_pair(std::string(left->table_name()), std::string(left->field_name()))];
          const int right_cell_index = field_location[std::make_pair(std::string(right->table_name()), std::string(right->field_name()))];


          // std::cout << p_spec_len << " --- " << q_spec_len << std::endl;
          // std::cout << left_cell_index << " --- " << right_cell_index << std::endl;
          TupleCell left_cell, rigth_cell;
          if (left_cell_index < p_spec_len) {
            rc = p_tuple.cell_at(left_cell_index, left_cell);
          } else {
            rc = q_tuple.cell_at(left_cell_index - p_spec_len, left_cell);
          }
          if (rc != RC::SUCCESS) {
            return rc;
          }
          if (right_cell_index < p_spec_len) {
            rc = p_tuple.cell_at(right_cell_index, rigth_cell);
          } else {
            rc = q_tuple.cell_at(right_cell_index - p_spec_len, rigth_cell);
          }
          if (rc != RC::SUCCESS) {
            return rc;
          }

          if (!tuple_cell_comp(left_cell, rigth_cell, filter->comp())) {
            save = false;
            break;
          }
        }
        if (save) {
          std::vector<TupleCell> mt;
          mt.insert(mt.end(), p_tuple.tuple().begin(), p_tuple.tuple().end());
          mt.insert(mt.end(), q_tuple.tuple().begin(), q_tuple.tuple().end());
          assert(mt.size() == spec_len);
          tuples.emplace_back(MagicTuple(mt));
        }
      }
    }

    result->set_tuples(tuples);
    speces.clear();   // 真正析构时才释放内存, 避免多次申请内存 
    field_location.clear();
    return rc;
  }

  RC print_set(std::ostream &os, const std::vector<Field> &query_fields) const
  {
    std::vector<int> query_index(query_fields.size(), -1);
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      for (int j = 0 ; j < speces_.size() ; ++ j) {
        const char *table_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->table_name();
        const char *field_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->field_name();
        if (0 == strcmp(query_fields[i].table_name(), table_name) && 0 == strcmp(query_fields[i].field_name(), field_name)) {
          query_index[i] = j;
          break;
        }
      }
      if (query_index[i] == -1) {
        LOG_ERROR("not match query field in tuple set.");
        return RC::SCHEMA_FIELD_MISSING;
      }
      
      if (i != 0) {
        os << "|";
      }

      if (speces_[query_index[i]]->alias()) {
        os << speces_[query_index[i]]->alias(); // TODO: 多表需要带表名, 可能需要处理常数字段
      }
    }
    if (query_fields.size() > 0) {
      os << "\n";
    }

    TupleCell cell;
    RC rc = RC::SUCCESS;
    bool first_field;
    for (auto tuple : tuples_) {
      first_field = true;
      for (auto i : query_index) {
        rc = tuple.cell_at(i, cell);
        if (rc != RC::SUCCESS) {
          LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
          break;
        }

        if (!first_field) {
          os << " | ";
        } else {
          first_field = false;
        }
        cell.to_string(os);
      }
      os << std::endl;
    }
    return RC::SUCCESS;
  }

  RC print_agg_set(std::ostream &os, const std::vector<Field> &query_fields)
  {
    std::vector<int> query_index(query_fields.size(), -1);
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      for (int j = 0 ; j < speces_.size() ; ++ j) {
        const char *table_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->table_name();
        const char *field_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->field_name();
        if (0 == strcmp(query_fields[i].table_name(), table_name) && 0 == strcmp(query_fields[i].field_name(), field_name)) {
          query_index[i] = j;
          break;
        }
      }
      if (query_index[i] == -1) {
        LOG_ERROR("not match query field in tuple set.");
        return RC::SCHEMA_FIELD_MISSING;
      }

      if (i != 0) {
        os << "|";
      }

      if (speces_[query_index[i]]->alias()) {
        char tmp[255];
        if (0 == strcmp(query_fields[i].agg_str(), "*") || is_number(query_fields[i].agg_str())) {
          strcpy(tmp, query_fields[i].agg_str());
        } else {
          strcpy(tmp, speces_[query_index[i]]->alias());
        }
        char alias[255];
        switch (query_fields[i].agg_type()) {
          case AGG_MAX:
            sprintf(alias, "MAX(%s)", tmp);
            break;
          case AGG_MIN:
            sprintf(alias, "MIN(%s)", tmp);
            break;
          case AGG_SUM:
            sprintf(alias, "SUM(%s)", tmp);
            break;
          case AGG_COUNT:
            sprintf(alias, "COUNT(%s)", tmp);
            break;
          case AGG_AVG:
            sprintf(alias, "AVG(%s)", tmp);
            break;
          default:
            LOG_WARN("unknown aggregation function");
            return RC::INVALID_ARGUMENT;
        }
        os << alias; // TODO: 多表需要带表名, 可能需要处理常数字段
      }
    }
    if (query_fields.size() > 0) {
      os << "\n";
    }

    TupleCell cell;
    RC rc = RC::SUCCESS;
    bool first_field;
    first_field = true;
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      TupleCell cell;
      switch (query_fields[i].agg_type()) {
        case AGG_MAX:
          rc = max_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_MIN:
          rc = min_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_SUM:
          rc = sum_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_COUNT:
          if (0 == strcmp(query_fields[i].agg_str(), "*") || is_number(query_fields[i].agg_str())) {
            rc = count_cell(query_index[i], cell, false);
          } else {
            rc = count_cell(query_index[i], cell, true);
          }
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_AVG:
          rc = avg_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        default:
          LOG_WARN("unknown aggregation function");
          return RC::INVALID_ARGUMENT;
      }
      if (!first_field) {
        os << " | ";
      } else {
        first_field = false;
      }
      cell.to_string(os);
    }
    os << std::endl;
    return RC::SUCCESS;
  }

  RC get_set(std::vector<Value> &value_list, const std::vector<Field> &query_fields) const
  {
    std::vector<int> query_index(query_fields.size(), -1);
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      for (int j = 0 ; j < speces_.size() ; ++ j) {
        const char *table_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->table_name();
        const char *field_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->field_name();
        if (0 == strcmp(query_fields[i].table_name(), table_name) && 0 == strcmp(query_fields[i].field_name(), field_name)) {
          query_index[i] = j;
          break;
        }
      }
      if (query_index[i] == -1) {
        LOG_ERROR("not match query field in tuple set.");
        return RC::SCHEMA_FIELD_MISSING;
      }
    }
    TupleCell cell;
    RC rc = RC::SUCCESS;
    for (auto tuple : tuples_) {
      for (auto i : query_index) {
        rc = tuple.cell_at(i, cell);
        if (rc != RC::SUCCESS) {
          LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
          break;
        }
        Value value;
        value.type = cell.attr_type();
        value.data = malloc(cell.length());
        memcpy(value.data, cell.data(), cell.length());
        value_list.push_back(value);
      }
    }
    return RC::SUCCESS;
  }

  RC get_agg_set(std::vector<Value> &value_list, const std::vector<Field> &query_fields) {
    std::vector<int> query_index(query_fields.size(), -1);
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      for (int j = 0 ; j < speces_.size() ; ++ j) {
        const char *table_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->table_name();
        const char *field_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->field_name();
        if (0 == strcmp(query_fields[i].table_name(), table_name) && 0 == strcmp(query_fields[i].field_name(), field_name)) {
          query_index[i] = j;
          break;
        }
      }
      if (query_index[i] == -1) {
        LOG_ERROR("not match query field in tuple set.");
        return RC::SCHEMA_FIELD_MISSING;
      }
    }

    TupleCell cell;
    RC rc = RC::SUCCESS;
    bool first_field;
    first_field = true;
    for (int i = 0 ; i < query_fields.size() ; ++ i) {
      TupleCell cell;
      switch (query_fields[i].agg_type()) {
        case AGG_MAX:
          rc = max_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_MIN:
          rc = min_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_SUM:
          rc = sum_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_COUNT:
          if (0 == strcmp(query_fields[i].agg_str(), "*") || is_number(query_fields[i].agg_str())) {
            rc = count_cell(query_index[i], cell, false);
          } else {
            rc = count_cell(query_index[i], cell, true);
          }
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        case AGG_AVG:
          rc = avg_cell(query_index[i], cell);
          LOG_INFO("failed to aggregate. index=%d, rc=%s", i, strrc(rc));
          break;
        default:
          LOG_WARN("unknown aggregation function");
          return RC::INVALID_ARGUMENT;
      }
      Value value;
      value.type = cell.attr_type();
      value.data = malloc(cell.length());
      memcpy(value.data, cell.data(), cell.length());
      value_list.push_back(value);
    }
    return RC::SUCCESS;
  }
  static bool compare_tuple(MagicTuple tuple1, MagicTuple tuple2)
  {
    for (int i = 0; i < order_index_.size(); ++i) {
      TupleCell cell1, cell2;
      tuple1.cell_at(order_index_[i], cell1);
      tuple2.cell_at(order_index_[i], cell2);
      int res = cell1.compare(cell2);

      if (cell1.attr_type() == NULL_ && cell2.attr_type() != NULL_) res = -1;
      if (cell1.attr_type() != NULL_ && cell2.attr_type() == NULL_) res = 1;
      if (res != 0) {
        if (order_type_[i] == ORDER_ASC)
          return res < 0;
        else if (order_type_[i] == ORDER_DESC)
          return res > 0;
      }
    }
    return false;
  }

public:
  void set_speces(const std::vector<TupleCellSpec*> &speces) { speces_ = speces; }
  void set_tuples(const std::vector<MagicTuple> &tuples) { tuples_ = tuples; }
  std::vector<MagicTuple> tuples() { return tuples_; }

  RC set_order_index(const std::vector<OrderField> &order_fields)
  {
    order_index_ = std::vector<int>(order_fields.size(), -1);
    order_type_ = std::vector<OrderType>(order_fields.size(), ORDER_ASC);
    for (int i = 0 ; i < order_fields.size() ; ++ i) {
      order_type_[i] = order_fields[i].order_type();
      for (int j = 0 ; j < speces_.size() ; ++ j) {
        const char *table_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->table_name();
        const char *field_name = dynamic_cast<FieldExpr*>(speces_[j]->expression())->field_name();
        if (0 == strcmp(order_fields[i].table_name(), table_name) && 0 == strcmp(order_fields[i].field_name(), field_name)) {
          order_index_[i] = j;
          break;
        }
      }
      if (order_index_[i] == -1) {
        LOG_ERROR("not match order field in tuple set.");
        return RC::SCHEMA_FIELD_MISSING;
      }
    }
    return RC::SUCCESS;
  }

private:
  std::vector<TupleCellSpec*> speces_;
  std::vector<MagicTuple> tuples_;
  static std::vector<int> order_index_;
  static std::vector<OrderType> order_type_;

  RC max_cell(int j, TupleCell & cell)
  {
    if (tuples_.size() == 0) {
      return RC::SUCCESS;
    }
    TupleCell cell1;
    tuples_[0].cell_at(j, cell1);
    cell.set_type(cell1.attr_type());
    cell.set_length(cell1.length());
    cell.set_data(cell1.data());
    AttrType attr_type = cell.attr_type();
    for (int i = 1; i < tuples_.size(); ++i) {
      TupleCell cell2;
      tuples_[i].cell_at(j, cell2);
      if (cell.compare(cell2) < 0 || cell.attr_type() == NULL_) {
        cell.set_type(cell2.attr_type());
        cell.set_length(cell2.length());
        cell.set_data(cell2.data());
      }
    }
    return RC::SUCCESS;
  }

  RC min_cell(int j, TupleCell & cell)
  {
    if (tuples_.size() == 0) {
      return RC::SUCCESS;
    }
    TupleCell cell1;
    tuples_[0].cell_at(j, cell1);
    cell.set_type(cell1.attr_type());
    cell.set_length(cell1.length());
    cell.set_data(cell1.data());
    AttrType attr_type = cell.attr_type();
    for (int i = 1; i < tuples_.size(); ++i) {
      TupleCell cell2;
      tuples_[i].cell_at(j, cell2);
      if (cell.compare(cell2) > 0 || cell.attr_type() == NULL_) {
        cell.set_type(cell2.attr_type());
        cell.set_length(cell2.length());
        cell.set_data(cell2.data());
      }
    }
    return RC::SUCCESS;
  }

  RC sum_cell(int j, TupleCell & cell)
  {
    if (tuples_.size() == 0) {
      return RC::SUCCESS;
    }
    TupleCell cell1;
    tuples_[0].cell_at(j, cell1);
    cell.set_type(cell1.attr_type());
    cell.set_length(cell1.length());
    cell.set_data(cell1.data());

    int first_not_null = 1;
    while (cell.attr_type() == NULL_ && first_not_null < tuples_.size()) {
      tuples_[first_not_null ++].cell_at(j, cell1);
      cell.set_type(cell1.attr_type());
      cell.set_length(cell1.length());
      cell.set_data(cell1.data());
    }

    AttrType attr_type = cell.attr_type();
    if (attr_type == INTS) {
      int n = (int)*cell.data();
      for (int i = first_not_null; i < tuples_.size(); ++i) {
        TupleCell cell2;
        tuples_[i].cell_at(j, cell2);
        if (cell2.attr_type() == NULL_) continue;
        n += (int)*cell2.data();
      }
      char *data = (char *)malloc(sizeof(int)); // 这里有内存泄漏
      memcpy(data, (char *)&n, sizeof(int));
      cell.set_data(data);
      cell.set_type(cell.attr_type());
      cell.set_length(sizeof(int));
    } else if (attr_type == FLOATS) {
      float n = string_to_float(double2string(*(float*)cell.data()).c_str());
      for (int i = first_not_null; i < tuples_.size(); ++i) {
        TupleCell cell2;
        tuples_[i].cell_at(j, cell2);
        if (cell2.attr_type() == NULL_) continue;
        n += string_to_float(double2string(*(float*)cell2.data()).c_str());
      }
      char * data = (char * )malloc(sizeof(float));
      memcpy(data, (char *)&n, sizeof(float));
      cell.set_data(data);
      cell.set_type(FLOATS);
      cell.set_length(sizeof(float));
    } else if (attr_type == CHARS) {
      float n = string_to_float(cell.data());
      for (int i = first_not_null; i < tuples_.size(); ++i) {
        TupleCell cell2;
        tuples_[i].cell_at(j, cell2);
        if (cell2.attr_type() == NULL_) continue;
        n += string_to_float(cell2.data());
      }
      char * data = (char * )malloc(sizeof(float));
      memcpy(data, (char *)&n, sizeof(float));
      cell.set_data(data);
      cell.set_type(FLOATS);
      cell.set_length(sizeof(float));
    } else { // NULL
      // 无需处理
    }
    return RC::SUCCESS;
  }

  RC count_cell(int j, TupleCell & cell, bool ignore_null)
  {
    int n = 0;
    for (int i = 0; i < tuples_.size(); ++i) {
      TupleCell cell2;
      tuples_[i].cell_at(j, cell2);
      if (ignore_null && cell2.attr_type() == NULL_) continue;
      if (cell2.data() != nullptr) {
        n++;
      }
    }
    char * data = (char * )malloc(sizeof(int));
    memcpy(data, (char *)&n, sizeof(int));
    cell.set_data(data);
    cell.set_type(INTS);
    cell.set_length(sizeof(int));
    return RC::SUCCESS;
  }

  RC avg_cell(int j, TupleCell & cell)
  {
    RC rc;
    TupleCell cell1, cell2;
    rc = sum_cell(j, cell1);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    rc = count_cell(j, cell2, true);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (cell1.attr_type() == NULL_ || cell2.attr_type() == NULL_) {
      void *data = malloc(sizeof(float));
      null_data(data, sizeof(float));
      cell.set_data((char*)data);
      cell.set_type(NULL_);
      cell.set_length(sizeof(float));

      return RC::SUCCESS;
    }

    float n;
    AttrType attr_type = cell1.attr_type();
    if (attr_type == INTS) {
      n = (float)*(int *)cell1.data();
    } else if (attr_type == FLOATS) {
      n = *(float *)cell1.data();
    }
    int m = *(int *)cell2.data();
    if (m == 0) {
      void *data = malloc(sizeof(float));
      null_data(data, sizeof(float));
      cell.set_data((char*)data);
      cell.set_type(NULL_);
    } else {
      n /= m;
      char * data = (char *)malloc(sizeof(float));
      memcpy(data, (char *)&n, sizeof(float));
      cell.set_data(data);
      cell.set_type(FLOATS);
    }
    cell.set_length(sizeof(float));
    return RC::SUCCESS;
  }
};

std::vector<int> TupleSet::order_index_;
std::vector<OrderType> TupleSet::order_type_;

void speces_copy(const std::vector<TupleCellSpec*> &src, std::vector<TupleCellSpec*> &dst, HashLocation &locat){
  int index = dst.size();
  for (auto spec : src) {
      assert(static_cast<FieldExpr*>(spec->expression()));
      FieldExpr *tmpf = static_cast<FieldExpr*>(spec->expression());
      TupleCellSpec *tmpt = new TupleCellSpec(new FieldExpr(tmpf->field().table(), tmpf->field().meta()));

      char *alia = (char*)malloc(strlen(spec->alias()) + 1);
      strcpy(alia, spec->alias());
      tmpt->set_alias(alia);
      dst.emplace_back(tmpt);
      locat[std::make_pair(std::string(tmpf->field().table_name()), std::string(tmpf->field().field_name()))] = index ++;
  }
}

bool tuple_cell_comp(TupleCell &left, TupleCell &right, CompOp comp) {
  if (comp != EQUAL_IS && comp != NOT_EQUAL_IS) {
    if (left.attr_type() == NULL_ || right.attr_type() == NULL_){
      return false;
    }
  }

  const int compare = left.compare(right);
  bool filter_result = false;
  switch (comp) {
  case EQUAL_TO: {
    filter_result = (0 == compare); 
  } break;
  case LESS_EQUAL: {
    filter_result = (compare <= 0); 
  } break;
  case NOT_EQUAL: {
    filter_result = (compare != 0);
  } break;
  case LESS_THAN: {
    filter_result = (compare < 0);
  } break;
  case GREAT_EQUAL: {
    filter_result = (compare >= 0);
  } break;
  case GREAT_THAN: {
    filter_result = (compare > 0);
  } break;
  case OP_LIKE: {
    filter_result = like(left.data(), right.data(), left.length());
    LOG_INFO("left_value=%s, right_value=%s, filter_result=%d", left.data(), right.data(), filter_result);
  } break;
  case OP_NOT_LIKE: {
    filter_result = !like(left.data(), right.data(), left.length());
    LOG_INFO("left_value=%s, right_value=%s, filter_result=%d", left.data(), right.data(), filter_result);
  } break;
  case EQUAL_IS: {
      filter_result = (left.attr_type() == NULL_);
    } break;
  case NOT_EQUAL_IS: {
    filter_result = (left.attr_type() != NULL_);;
  } break;
  default: {
    LOG_WARN("invalid compare type: %d", comp);
  } break;
  }
  if (!filter_result) {
    return false;
  }
  return true;
}