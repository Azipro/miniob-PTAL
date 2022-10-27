#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "util/util.h"
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

public:
  void set_speces(const std::vector<TupleCellSpec*> &speces) { speces_ = speces; }
  void set_tuples(const std::vector<MagicTuple> &tuples) { tuples_ = tuples; }

private:
  std::vector<TupleCellSpec*> speces_;
  std::vector<MagicTuple> tuples_;
};

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
  default: {
    LOG_WARN("invalid compare type: %d", comp);
  } break;
  }
  if (!filter_result) {
    return false;
  }
  return true;
}