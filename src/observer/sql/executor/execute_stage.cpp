/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Meiyi & Longda on 2021/4/13.
//
#pragma once

#include <string>
#include <sstream>
#include <algorithm>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/lang/defer.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/expr/tuple.h"
#include "sql/expr/tuple_set.h"
#include "sql/operator/table_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/update_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/table.h"
#include "storage/common/field.h"
#include "storage/index/index.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/trx/trx.h"
#include "storage/clog/clog.h"

using namespace common;

//RC create_selection_executor(
//   Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag)
{}

//! Destructor
ExecuteStage::~ExecuteStage()
{}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag)
{
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties()
{
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize()
{
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup()
{
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::handle_request(common::StageEvent *event)
{
  SQLStageEvent *sql_event = static_cast<SQLStageEvent *>(event);
  SessionEvent *session_event = sql_event->session_event();
  Stmt *stmt = sql_event->stmt();
  Session *session = session_event->session();
  Query *sql = sql_event->query();

  if (stmt != nullptr) {
    switch (stmt->type()) {
    case StmtType::SELECT: {
      do_select(sql_event);
    } break;
    case StmtType::INSERT: {
      do_insert(sql_event);
    } break;
    case StmtType::UPDATE: {
      do_update(sql_event);
    } break;
    case StmtType::DELETE: {
      do_delete(sql_event);
    } break;
    default: {
      LOG_WARN("should not happen. please implenment");
    } break;
    }
  } else {
    switch (sql->flag) {
    case SCF_HELP: {
      do_help(sql_event);
    } break;
    case SCF_CREATE_TABLE: {
      do_create_table(sql_event);
    } break;
    case SCF_CREATE_INDEX: {
      do_create_index(sql_event);
    } break;
    case SCF_SHOW_INDEXES: {
      do_show_index(sql_event);
    } break;
    case SCF_SHOW_TABLES: {
      do_show_tables(sql_event);
    } break;
    case SCF_DESC_TABLE: {
      do_desc_table(sql_event);
    } break;
    case SCF_DROP_TABLE: {
      do_drop_table(sql_event);
      break;
    }
    case SCF_DROP_INDEX:
    case SCF_LOAD_DATA: {
      default_storage_stage_->handle_event(event);
    } break;
    case SCF_SYNC: {
      /*
      RC rc = DefaultHandler::get_default().sync();
      session_event->set_response(strrc(rc));
      */
    } break;
    case SCF_BEGIN: {
      do_begin(sql_event);
      /*
      session_event->set_response("SUCCESS\n");
      */
    } break;
    case SCF_COMMIT: {
      do_commit(sql_event);
      /*
      Trx *trx = session->current_trx();
      RC rc = trx->commit();
      session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
      */
    } break;
    case SCF_CLOG_SYNC: {
      do_clog_sync(sql_event);
    }
    case SCF_ROLLBACK: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->rollback();
      session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
    } break;
    case SCF_EXIT: {
      // do nothing
      const char *response = "Unsupported\n";
      session_event->set_response(response);
    } break;
    default: {
      LOG_ERROR("Unsupported command=%d\n", sql->flag);
    }
    }
  }
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right)
{
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}

void print_tuple_header(std::ostream &os, const ProjectOperator &oper)
{
  const int cell_num = oper.tuple_cell_num();
  const TupleCellSpec *cell_spec = nullptr;
  for (int i = 0; i < cell_num; i++) {
    oper.tuple_cell_spec_at(i, cell_spec);
    if (i != 0) {
      os << " | ";
    }

    if (cell_spec->alias()) {
      os << cell_spec->alias();
    }
  }

  if (cell_num > 0) {
    os << '\n';
  }
}
void tuple_to_string(std::ostream &os, const Tuple &tuple)
{
  TupleCell cell;
  RC rc = RC::SUCCESS;
  bool first_field = true;
  for (int i = 0; i < tuple.cell_num(); i++) {
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
}

void add_tupleset_header(TupleSet *magic_table, const ProjectOperator &oper) {
  std::vector<TupleCellSpec*> speces;
  const int cell_num = oper.tuple_cell_num();
  const TupleCellSpec *cell_spec = nullptr;
  for (int i = 0; i < cell_num; i++) {
    oper.tuple_cell_spec_at(i, cell_spec);

    assert(static_cast<FieldExpr*>(cell_spec->expression()));
    FieldExpr *tmpf = static_cast<FieldExpr*>(cell_spec->expression());
    TupleCellSpec *tmpt = new TupleCellSpec(new FieldExpr(tmpf->field().table(), tmpf->field().meta()));

    char *alia = (char*)malloc(strlen(cell_spec->alias()) + 1);
    strcpy(alia, cell_spec->alias());
    tmpt->set_alias(alia);
    speces.emplace_back(tmpt);
  }
  magic_table->set_speces(speces);
}

void tuple_to_magic_tuple(Tuple *tuple, MagicTuple &magic_tuple) {
  std::vector<TupleCell> tmp_tuple;
  TupleCell cell;
  RC rc = RC::SUCCESS;
  for (int i = 0; i < tuple->cell_num(); i++) {
    rc = tuple->cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
      break;
    }
    tmp_tuple.emplace_back(cell);
  }
  magic_tuple.set_tuple(tmp_tuple);
}

IndexScanOperator *try_to_create_index_scan_operator(FilterStmt *filter_stmt, const Table *table) // 只支持一个表
{
  const std::vector<FilterUnit *> &filter_units = filter_stmt->filter_units();
  if (filter_units.empty() ) {
    return nullptr;
  }

  // 在所有过滤条件中，找到字段与值做比较的条件，然后判断字段是否可以使用索引
  // 如果是多列索引，这里的处理需要更复杂。
  // 这里的查找规则是比较简单的，就是尽量找到使用相等比较的索引
  // 如果没有就找范围比较的，但是直接排除不等比较的索引查询. (你知道为什么?)
  
  std::vector<const FilterUnit*> better_filter;
  const FilterUnit *better_filter_single = nullptr;
  const std::vector<Index *>& indexes = table->indexes();
  Index *better_index = nullptr;
  Index *better_index_single = nullptr;
  Index *better_index_multi = nullptr;

  for (const auto index : indexes) { // 优先多列索引, 再单列索引
    const std::vector<FieldMeta>& fields_meta = index->fields_meta();
    std::vector<const FilterUnit*> better_filter_tmp;

    for (int i = 0 ; i < fields_meta.size() ; ++ i) {
      const FieldMeta field = fields_meta[i];

      for (const FilterUnit * filter_unit : filter_units) {

        if (filter_unit->comp() == NOT_EQUAL || filter_unit->comp() == NOT_EQUAL_IS) {
          continue;
        }
        Expression *left = filter_unit->left();
        Expression *right = filter_unit->right();
        CompOp comp = filter_unit ->comp();
        if (left->type() == ExprType::FIELD && right->type() == ExprType::VALUE) {
        } else if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
          std::swap(left, right);
        } else if (left->type() == ExprType::VALUE && right->type() == ExprType::VALUE) { // value comp value 直接跳过
          continue;
        }
        FieldExpr &left_field_expr = *(FieldExpr *)left;
        const Field &field_match = left_field_expr.field();

        if (0 == strcmp(field.name(), field_match.field_name())) {
          if (fields_meta.size() > 1) { // 多列索引
            // 这里简单处理: 只有最后一个字段作比较, 前面字段都是EQUAL_TO, 才走多列索引
            if ((i != fields_meta.size() - 1) && comp != EQUAL_TO) {
              continue; // 尝试继续找相等
            } else if (i != fields_meta.size() - 1) {
              better_filter_tmp.push_back(filter_unit);
              break;
            } else {
              better_filter_tmp.push_back(filter_unit);
              break;
            }
          } else { // 单列索引
            if (better_filter_single == nullptr) {
              better_filter_single = filter_unit;
              better_index_single = index;
            } else if (comp == EQUAL_TO || comp == EQUAL_IS) {
              better_filter_single = filter_unit;
              better_index_single = index;
            }
          }
        } else {
          continue;
        }
      }
    }
    
    if (better_filter_tmp.size() == fields_meta.size()) { // 找到多列索引, 尽可能匹配最长的索引
      if (better_filter.size() < better_filter_tmp.size()){
        better_filter = better_filter_tmp;
        better_index_multi = index;
      }
    }
  }
  

  if (better_filter_single == nullptr && better_filter.size() == 0) {
    return nullptr;
  }

  bool multi_index = (better_filter.size() == 0) ? false : true;

  if (multi_index) {
    better_index = better_index_multi;
  } else {
    better_index = better_index_single;
  }

  char *user_key = nullptr;
  const char *left_user_key = nullptr;
  const char *right_user_key = nullptr;
  int  attr_num = better_filter.size();
  int  attr_len[MAX_NUM];
  bool left_inclusive = false;
  bool right_inclusive = false;

  Expression *left;
  Expression *right;
  CompOp comp;
  int user_key_offest = 0;
  if (multi_index) {
    // 除了最后一个都是等于关系
    for (int i = 0 ; i < better_filter.size() ; ++ i) {
      const FilterUnit *filter = better_filter[i];
      left = filter->left();
      right = filter->right();
      comp = filter -> comp();
      if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
        std::swap(left, right);
        switch (comp) {
          case EQUAL_TO:      { comp = EQUAL_TO; }    break;
          case LESS_EQUAL:    { comp = GREAT_THAN; }  break;
          case NOT_EQUAL:     { comp = NOT_EQUAL; }   break;
          case LESS_THAN:     { comp = GREAT_EQUAL; } break;
          case GREAT_EQUAL:   { comp = LESS_THAN; }   break;
          case GREAT_THAN:    { comp = LESS_EQUAL; }  break;
          case EQUAL_IS:      { comp = EQUAL_IS; }    break;
          default: {
            LOG_WARN("should not happen");
          }
        }
      }
      FieldExpr &left_field_expr = *(FieldExpr *)left;
      ValueExpr &right_value_expr = *(ValueExpr *)right;
      TupleCell value;
      right_value_expr.get_tuple_cell(value);
      if (value.attr_type() == CHARS) {
        attr_len[i] = value.length();
      } else if (value.attr_type() == NULL_) { // 这里需要提前fix user key, 当然也可以在b+ tree再fix
        attr_len[i] = left_field_expr.field().field_meta()->len();
        void *data = malloc(attr_len[i]);
        null_data(data, attr_len[i]);
        value.set_data((char*)data);
      } else {
        attr_len[i] = 4; // 其他类型固定4bytes
      }
    
      char *tmp = user_key;
      user_key = (char*)malloc(user_key_offest + attr_len[i]);
      memmove(user_key, tmp, user_key_offest);
      memmove(user_key + user_key_offest, value.data(), attr_len[i]);
      if (tmp != nullptr) {
        free(tmp);
      }
      user_key_offest += attr_len[i];
    }
  } else {
    attr_num = 1;
    left = better_filter_single->left();
    right = better_filter_single->right();
    comp = better_filter_single -> comp();
    if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
      switch (comp) {
        case EQUAL_TO:      { comp = EQUAL_TO; }    break;
        case LESS_EQUAL:    { comp = GREAT_THAN; }  break;
        case NOT_EQUAL:     { comp = NOT_EQUAL; }   break;
        case LESS_THAN:     { comp = GREAT_EQUAL; } break;
        case GREAT_EQUAL:   { comp = LESS_THAN; }   break;
        case GREAT_THAN:    { comp = LESS_EQUAL; }  break;
        case EQUAL_IS:      { comp = EQUAL_IS; }    break;
        default: {
          LOG_WARN("should not happen");
        }
      }
    }
    
    FieldExpr &left_field_expr = *(FieldExpr *)left;
    ValueExpr &right_value_expr = *(ValueExpr *)right;
    TupleCell value;
    right_value_expr.get_tuple_cell(value);
    if (value.attr_type() == CHARS) {
      attr_len[0] = value.length();
    } else if (value.attr_type() == NULL_) { // 这里需要提前fix user key, 当然也可以在b+ tree再fix
      attr_len[0] = left_field_expr.field().field_meta()->len();
      void *data = malloc(attr_len[0]);
      null_data(data, (size_t)attr_len[0]);
      value.set_data((char*)data);
    } else {
      attr_len[0] = 4; // 其他类型固定4bytes
    }
    
    user_key = (char*)malloc(attr_len[0]);
    memmove(user_key, value.data(), attr_len[0]);

    LOG_INFO("%s", is_null(user_key, attr_len[0]) ? "null" : "not null");
  }

  switch (comp) {
  case EQUAL_TO: {
    left_user_key = user_key;
    right_user_key = user_key;
    left_inclusive = true;
    right_inclusive = true;
  } break;

  case LESS_EQUAL: {
    left_user_key = nullptr;
    left_inclusive = false;
    right_user_key = user_key;
    right_inclusive = true;
  } break;

  case LESS_THAN: {
    left_user_key = nullptr;
    left_inclusive = false;
    right_user_key = user_key;
    right_inclusive = false;
  } break;

  case GREAT_EQUAL: {
    left_user_key = user_key;
    left_inclusive = true;
    right_user_key = nullptr;
    right_inclusive = false;
  } break;

  case GREAT_THAN: {
    left_user_key = user_key;
    left_inclusive = false;
    right_user_key = nullptr;
    right_inclusive = false;
  } break;

  case EQUAL_IS: {
    left_user_key = user_key;
    right_user_key = user_key;
    left_inclusive = true;
    right_inclusive = true;
  } break;

  default: {
    LOG_WARN("should not happen. comp=%d", comp);
  } break;
  }

  IndexScanOperator *oper = new IndexScanOperator(table, better_index,
       left_user_key, left_inclusive, right_user_key, right_inclusive, attr_len, attr_num);

  LOG_INFO("use index for scan: %s in table %s", better_index->index_meta().name(), table->name());
  return oper;
}

RC ExecuteStage::do_select(SQLStageEvent *sql_event)
{
  SelectStmt *select_stmt = (SelectStmt *)(sql_event->stmt());
  SessionEvent *session_event = sql_event->session_event();
  TupleSet *magic_table = nullptr;
  RC rc = RC::SUCCESS;
  if (select_stmt->tables().size() == 1) {
    rc = do_select_table(select_stmt, magic_table, false);
  } else if (select_stmt->tables().size() > 1) {
    rc = do_select_tables(select_stmt, magic_table, true);
  } else {
    LOG_WARN("select less than 1 tables is not supported");
    return RC::UNIMPLENMENT;
  }
  
  if (rc != RC::SUCCESS || magic_table == nullptr) {
    LOG_ERROR("select result to a tuple set failed.");
    return rc;
  }

  if (select_stmt->order_fields().size() > 0) {
    rc = magic_table->set_order_index(select_stmt->order_fields());
    if (rc != RC::SUCCESS) {
      LOG_WARN("set order index failed.");
      return rc;
    }
    std::vector<MagicTuple> tuples = magic_table->tuples();
    sort(tuples.begin(), tuples.end(), magic_table->compare_tuple);
    magic_table->set_tuples(tuples);
  }

  std::stringstream ss;
  if (select_stmt->agg_num() > 0) {
    rc = magic_table->print_agg_set(ss, select_stmt->query_fields());
  } else {
    rc = magic_table->print_set(ss, select_stmt->query_fields());
  }
  if (rc != RC::SUCCESS) {
    return rc;
  }
  session_event->set_response(ss.str());
  delete magic_table;
  return rc;
}

RC ExecuteStage::do_select_table(SelectStmt *select_stmt, TupleSet *&magic_table, bool is_tables) {
  assert(select_stmt->tables().size() == 1);
  RC rc = RC::SUCCESS;
  Operator *scan_oper = try_to_create_index_scan_operator(select_stmt->filter_stmt(), select_stmt->tables()[0]);
  if (nullptr == scan_oper) {
    scan_oper = new TableScanOperator(select_stmt->tables()[0]);
  }

  DEFER([&] () {delete scan_oper;});

  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta(), &is_tables);
  }

  rc = project_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }

  magic_table = new TupleSet();
  add_tupleset_header(magic_table, project_oper);
  LOG_INFO("begin to scan records.");
  std::vector<MagicTuple> tuples;
  while ((rc = project_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple = project_oper.current_tuple();
    MagicTuple magic_tuple;
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }
    tuple_to_magic_tuple(tuple, magic_tuple);
    tuples.emplace_back(magic_tuple);
  }
  magic_table->set_tuples(tuples);
  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    project_oper.close();
  } else {
    rc = project_oper.close();
  }
  return rc;
}

RC ExecuteStage::do_sub_query(Db *db, Query* query, std::vector<Value> &value_list){
  Stmt *stmt = nullptr;
  RC rc = Stmt::create_stmt(db, *query, stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create stmt. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  switch (query->flag) {
    case SCF_SELECT: {
      SelectStmt *select_stmt = (SelectStmt *)stmt;
      TupleSet *magic_table = nullptr;
      RC rc = RC::SUCCESS;
      if (select_stmt->tables().size() == 1) {
        rc = do_select_table(select_stmt, magic_table, false);
      } else if (select_stmt->tables().size() > 1) {
        rc = do_select_tables(select_stmt, magic_table, true);
      } else {
        LOG_WARN("select less than 1 tables is not supported");
        return RC::UNIMPLENMENT;
        ;
      }
      if (select_stmt->agg_num() > 0) {
        rc = magic_table->get_agg_set(value_list, select_stmt->query_fields());
      } else {
        rc = magic_table->get_set(value_list, select_stmt->query_fields());
      }
      if (rc != RC::SUCCESS) {
        return rc;
      }
      delete magic_table;
      return rc;
      break;
    }
    default: {
      LOG_WARN("unimplenment query");
      rc = RC::UNIMPLENMENT;
      return rc;
    }
  }
}

RC ExecuteStage::do_select_tables(SelectStmt *select_stmt, TupleSet *&magic_table, bool is_tables) {
  assert(select_stmt->tables().size() > 1);
  RC rc = RC::SUCCESS;
  bool is_fisrt_table = true;
  TupleSet *current_table_set;
  TupleSet *tmp_result;

  for (int i = 0 ; i < select_stmt->tables().size() ; ++ i) {
    const Table *table = select_stmt->tables()[i];
    SelectStmt *ss = new SelectStmt();
    FilterStmt *filter_stmt = new FilterStmt();
    std::vector<Field> query_fields;
    std::vector<FilterUnit *> fu;

    // 查出全部字段, 后续表间comp需要使用
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num();
    for (int i = table_meta.sys_field_num(); i < field_num; i++) {
      query_fields.push_back(Field(table, table_meta.field(i)));
    }

    // TODO: 这里还可以优化, 预处理出之后filter需要用到的字段, 再结合需要query的字段，就可以剔除大部分无用数据
    // 找出与这张表相关的filter, 剩下没有使用的comp都是不同表之间的比较
    for(auto filter : select_stmt->filter_stmt()->filter_units()) {
      if (filter->left()->type() == ExprType::FIELD) {
          const char *table_name = static_cast<FieldExpr*>(filter->left())->table_name();
          if (0 != strcmp(table->name(), table_name)) {
            continue;
          }
      }
      if (filter->right()->type() == ExprType::FIELD) {
          const char *table_name = static_cast<FieldExpr*>(filter->right())->table_name();
          if (0 != strcmp(table->name(), table_name)) {
            continue;
          }
      }

      Expression *left = nullptr;
      Expression *right = nullptr;
      // 重新分配filter相关资源, 防止析构掉还需要使用的部分
      if (filter->left()->type() == ExprType::FIELD) {
        Field t = static_cast<FieldExpr*>(filter->left())->field();
        left = new FieldExpr(t.table(), t.meta());
      } else {
        TupleCell t;
        static_cast<ValueExpr*>(filter->left())->get_tuple_cell(t);
        Value v;
        v.type = t.attr_type();
        v.data = (void *)t.data();
        left = new ValueExpr(v);
      }

      if (filter->right()->type() == ExprType::FIELD) {
        Field t = static_cast<FieldExpr*>(filter->right())->field();
        right = new FieldExpr(t.table(), t.meta());
      } else {
        TupleCell t;
        static_cast<ValueExpr*>(filter->right())->get_tuple_cell(t);
        Value v;
        v.type = t.attr_type();
        v.data = (void *)t.data();
        right = new ValueExpr(v);
      }

      FilterUnit *t = new FilterUnit();
      t->set_comp(filter->comp());
      t->set_left(left);
      t->set_right(right);
      fu.push_back(t);
    }

    filter_stmt->set_filter_units(fu);
    ss->set_Filter(filter_stmt);
    ss->set_query_fields(query_fields);
    ss->set_tables(std::vector<Table*>{ const_cast<Table*>(table) });

    rc = do_select_table(ss, current_table_set, is_tables);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("select table %s failed.", table->name());
      return rc;
    }
    // 这样在内存中的数据只会在某些情况下短暂冗余部分字段
    if (is_fisrt_table) {
      tmp_result = current_table_set;
      is_fisrt_table = false;
      continue;
    }

    TupleSet *tmp = new TupleSet();
    rc = TupleSet::inner_join(tmp_result, current_table_set, tmp, select_stmt->filter_stmt());
    if (rc != RC::SUCCESS) {
      LOG_ERROR("join table set %d failed.", i);
    }
    delete tmp_result;
    delete current_table_set;
    tmp_result = tmp;

    delete ss;
  }

  magic_table = tmp_result; // 稍后析构
  return rc;
}

RC ExecuteStage::do_help(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const char *response = "show tables;\n"
                         "desc `table name`;\n"
                         "create table `table name` (`column name` `column type`, ...);\n"
                         "create index `index name` on `table` (`column`);\n"
                         "insert into `table` values(`value1`,`value2`);\n"
                         "update `table` set column=value [where `column`=`value`];\n"
                         "delete from `table` [where `column`=`value`];\n"
                         "select [ * | `columns` ] from `table`;\n";
  session_event->set_response(response);
  return RC::SUCCESS;
}

RC ExecuteStage::do_create_table(SQLStageEvent *sql_event)
{
  const CreateTable &create_table = sql_event->query()->sstr.create_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(create_table.relation_name,
			create_table.attribute_count, create_table.attributes);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_drop_table(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const DropTable &drop_table = sql_event ->query()->sstr.drop_table;
  Db *db = session_event->session()->get_current_db();
  RC rc = db->drop_table(drop_table.relation_name);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_create_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const CreateIndex &create_index = sql_event->query()->sstr.create_index;
  Table *table = db->find_table(create_index.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::string> attrs;
  for(size_t i = 0; i < create_index.attr_num; i++) {
    attrs.push_back(create_index.attributes[i]);
  }
  RC rc = table->create_index(nullptr, create_index.index_name, create_index.type, attrs);
  sql_event->session_event()->set_response(rc == RC::SUCCESS ? "SUCCESS\n" : "FAILURE\n");
  return rc;
}

RC ExecuteStage::do_show_tables(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  std::vector<std::string> all_tables;
  db->all_tables(all_tables);
  if (all_tables.empty()) {
    session_event->set_response("No table\n");
  } else {
    std::stringstream ss;
    for (const auto &table : all_tables) {
      ss << table << std::endl;
    }
    session_event->set_response(ss.str().c_str());
  }
  return RC::SUCCESS;
}

RC ExecuteStage::do_show_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const ShowIndex &show_index = sql_event->query()->sstr.show_index;
  Table *table = db->find_table(show_index.relation_name);
  if (table == nullptr) {
    session_event->set_response("FAILURE\n");
    return RC::SUCCESS;
  }
  std::vector<Index*> indexes = table->indexes();

  std::stringstream ss;
  ss << "Table|Non_unique|Key_name|Seq_in_index|Column_name\n";
  LOG_INFO("table %s has %d indexes.", table->name(), indexes.size());
  for (auto index : indexes) {
    const std::vector<FieldMeta> fields = index->fields_meta();
    LOG_INFO("index %s has %d fields.", index->index_meta().name(), fields.size());
    for (int i = 0 ; i < fields.size() ; ++ i) {
      int non_unique = index->index_meta().type() == UNIQUE_INDEX ? 0 : 1;
      ss << table->name() << "|" << non_unique << "|" << index->index_meta().name() << "|" << i + 1 << "|" << fields[i].name() << "\n";
    }
  }

  session_event->set_response(ss.str().c_str());

  return RC::SUCCESS;
}

RC ExecuteStage::do_desc_table(SQLStageEvent *sql_event)
{
  Query *query = sql_event->query();
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = query->sstr.desc_table.relation_name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;
  if (table != nullptr) {
    table->table_meta().desc(ss);
  } else {
    ss << "No such table: " << table_name << std::endl;
  }
  sql_event->session_event()->set_response(ss.str().c_str());
  return RC::SUCCESS;
}

RC ExecuteStage::do_insert(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  InsertStmt *insert_stmt = (InsertStmt *)stmt;
  Table *table = insert_stmt->table();
  RC rc = RC::SUCCESS;
  for (int i = 0 ; i < insert_stmt->inserts_amount() ; ++ i) {
    const Inserts_more insert = insert_stmt->inserts()[i];
    rc = table->insert_record(trx, insert.value_num, insert.values);
    if (rc != RC::SUCCESS) {
      // trx->rollback(); // 到后面到stage做rollback
      break;
    }
  }
  if (rc == RC::SUCCESS) {
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      } 

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    } else {
      session_event->set_response("SUCCESS\n");
    }
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

/*
create table t (id int, name char, col1 int, col2 int);
insert into t values(1, '111', 1, 1);
insert into t values(2, '222', 2, 2);
update t set col1 = 10;
select * from t;

create table Update_table_1 (ID int, T_NAME char, COL1 int, COL2 int);
insert into Update_table_1 values(1, 'N1', 0, 0);
insert into Update_table_1 values(2, 'N2', 0, 0);
insert into Update_table_1 values(4, 'N3', 0, 1);
select * from Update_table_1;
UPDATE Update_table_1 SET t_name='N02' WHERE col1=0 AND col2=0;
UPDATE Update_table_1 SET T_NAME='N02' WHERE COL1=0 AND COL2=0;

create table t (id int, name char, col1 int, col2 int);
insert into t values(1, '111', 1, 1);
insert into t values(2, '222', 2, 2);
select * from t;
update t set col1 = 10;
update t set col1 = 10, col2 = 20;
update t set col1 = '1a' where id=1;

update t set col1=(select col1 from t where t.id=2) where t.id=1;
update t set col1=(select col1 from t where t.id=2) where t.id=1;
update t set col1=(select col1 from t where id=2) where id=1;
update t set col1=(select col1 from t) where id=1;
update t set col2=(select count(id) from t) where id=1;
update t set col2=(select max(id) from t) where id=1;
update t set col1 = 1 where id=(select count(id) from t);
update t set col1=(select count(id) from t), col2=(select count(id) from t) where id=1;
update t set col1=(select count(id) from t), col2=(select max(id) from t) where id=1;
update t set  col1=(select count(id) from t), col2=(select max(id) from t) where id=(select min(id) from t);
update t set name=(select max(name) from t) where id=1;
update t set col1=(select max(name) from t) where id=1;
*/

RC  ExecuteStage::convert_value(Db *db, Value & value){
  if(value.type != QUERY){
    return RC::SUCCESS;
  }else{
    std::vector<Value> value_list;
    do_sub_query(db, (Query *)value.data, value_list);
    LOG_WARN("conver_value: value_list.length=%d", value_list.size());
    if(value_list.size() != 1){
      LOG_WARN("convert value failed, value_list.length=%d", value_list.size());
      return RC::INVALID_ARGUMENT;
    }else{
      value = value_list[0];
      return RC::SUCCESS;
    }
  }
}

RC ExecuteStage::do_update(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Trx *trx = session->current_trx();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();
  UpdateStmt *update_stmt = (UpdateStmt *)(sql_event->stmt());
  std::vector<SetValue> value_list = update_stmt->values_list();
  LOG_INFO("-----convert set value-----");
  for(int i = 0; i < value_list.size(); i++){
    if(value_list[i].value.type == QUERY){
      LOG_INFO("before convert value, value.type = %d", value_list[i].value.type);
      convert_value(db, value_list[i].value);
      LOG_INFO("after convert value, value.type = %d", value_list[i].value.type);
    }
  }
  LOG_INFO("-----convert condition-----");
  update_stmt->set_value_list(value_list);
  Condition condition_list[MAX_NUM];
  LOG_INFO("debug info, before conditions");
  update_stmt->conditions(condition_list);
  LOG_INFO("debug info, after conditions");
  int condition_num = update_stmt->condition_num();
  LOG_INFO("condition_num=%d", condition_num);
  for(int i = 0; i < condition_num; i++){
    //LOG_INFO("conditon-%d: left_attr:%s, rigth_attr:%s, left_is_attr:%d", i, condition_list[i].left_attr.attribute_name, condition_list[i].right_attr.attribute_name, condition_list[i].left_is_attr);
    if(condition_list[i].left_value.type == QUERY && condition_list[i].left_is_attr != 1){
      LOG_INFO("before convert left value, value.type = %d", condition_list[i].left_value.type);
      convert_value(db, condition_list[i].left_value);
      LOG_INFO("after convert left value, value.type = %d", condition_list[i].left_value.type);
    }
    if(condition_list[i].right_value.type == QUERY && condition_list[i].right_is_attr != 1){
      LOG_INFO("before convert right value, value.type = %d", condition_list[i].right_value.type);
      convert_value(db, condition_list[i].right_value);
      LOG_INFO("after convert right value, value.type = %d", condition_list[i].right_value.type);
    }
  }
  LOG_INFO("debug info, before set_conditions");
  update_stmt->set_conditions(condition_list, condition_num);
  LOG_INFO("debug info, after set_conditions");
  rc = update_stmt->update_filter(db);
  if(rc != RC::SUCCESS){
    session_event->set_response("FAILURE\n");
    return rc;
  }
  // Operator *scan_oper = try_to_create_index_scan_operator(update_stmt->filter_stmt(), update_stmt->table());
  // if (nullptr == scan_oper) {
  //   scan_oper = new TableScanOperator(update_stmt->table());
  // }
  // 不走索引, 因为更新索引entry的时候偷懒直接删除再插入, 扫描走索引可能会有bug
  Operator *scan_oper = new TableScanOperator(update_stmt->table());

  DEFER([&] () {delete scan_oper;});

  PredicateOperator pred_oper(update_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  UpdateOperator update_oper(update_stmt, trx);
  update_oper.add_child(&pred_oper);

  rc = update_oper.open();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    // trx和clog未处理
    // if (!session->is_trx_multi_operation_mode()) {
    //   CLogRecord *clog_record = nullptr;
    //   rc = clog_manager->clog_gen_record(CLogType::REDO_UPDATE, trx->get_current_id(), clog_record);
    //   if (rc != RC::SUCCESS || clog_record == nullptr) {
    //     session_event->set_response("FAILURE\n");
    //     return rc;
    //   }

    //   rc = clog_manager->clog_append_record(clog_record);
    //   if (rc != RC::SUCCESS) {
    //     session_event->set_response("FAILURE\n");
    //     return rc;
    //   } 

    //   trx->next_current_id();
    //   session_event->set_response("SUCCESS\n");
    // }
  }
  return rc;
}

RC ExecuteStage::do_delete(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  DeleteStmt *delete_stmt = (DeleteStmt *)stmt;
  TableScanOperator scan_oper(delete_stmt->table());
  PredicateOperator pred_oper(delete_stmt->filter_stmt());
  pred_oper.add_child(&scan_oper);
  DeleteOperator delete_oper(delete_stmt, trx);
  delete_oper.add_child(&pred_oper);

  RC rc = delete_oper.open();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      } 

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_begin(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(true);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_BEGIN, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

RC ExecuteStage::do_commit(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(false);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  trx->next_current_id();

  return rc;
}

RC ExecuteStage::do_clog_sync(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();

  rc = clog_manager->clog_sync();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}
