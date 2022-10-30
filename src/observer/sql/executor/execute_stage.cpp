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

IndexScanOperator *try_to_create_index_scan_operator(FilterStmt *filter_stmt)
{
  const std::vector<FilterUnit *> &filter_units = filter_stmt->filter_units();
  if (filter_units.empty() ) {
    return nullptr;
  }

  // 在所有过滤条件中，找到字段与值做比较的条件，然后判断字段是否可以使用索引
  // 如果是多列索引，这里的处理需要更复杂。
  // 这里的查找规则是比较简单的，就是尽量找到使用相等比较的索引
  // 如果没有就找范围比较的，但是直接排除不等比较的索引查询. (你知道为什么?)
  const FilterUnit *better_filter = nullptr;
  for (const FilterUnit * filter_unit : filter_units) {
    if (filter_unit->comp() == NOT_EQUAL) {
      continue;
    }

    Expression *left = filter_unit->left();
    Expression *right = filter_unit->right();
    if (left->type() == ExprType::FIELD && right->type() == ExprType::VALUE) {
    } else if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
    } else if (left->type() == ExprType::VALUE && right->type() == ExprType::VALUE) { // value comp value 直接跳过
      continue;
    }
    FieldExpr &left_field_expr = *(FieldExpr *)left;
    const Field &field = left_field_expr.field();
    const Table *table = field.table();
    Index *index = table->find_index_by_field(field.field_name());
    if (index != nullptr) {
      if (better_filter == nullptr) {
        better_filter = filter_unit;
      } else if (filter_unit->comp() == EQUAL_TO) {
        better_filter = filter_unit;
    	break;
      }
    }
  }

  if (better_filter == nullptr) {
    return nullptr;
  }

  Expression *left = better_filter->left();
  Expression *right = better_filter->right();
  CompOp comp = better_filter->comp();
  if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
    std::swap(left, right);
    switch (comp) {
    case EQUAL_TO:    { comp = EQUAL_TO; }    break;
    case LESS_EQUAL:  { comp = GREAT_THAN; }  break;
    case NOT_EQUAL:   { comp = NOT_EQUAL; }   break;
    case LESS_THAN:   { comp = GREAT_EQUAL; } break;
    case GREAT_EQUAL: { comp = LESS_THAN; }   break;
    case GREAT_THAN:  { comp = LESS_EQUAL; }  break;
    default: {
    	LOG_WARN("should not happen");
    }
    }
  }


  FieldExpr &left_field_expr = *(FieldExpr *)left;
  const Field &field = left_field_expr.field();
  const Table *table = field.table();
  Index *index = table->find_index_by_field(field.field_name());
  assert(index != nullptr);

  ValueExpr &right_value_expr = *(ValueExpr *)right;
  TupleCell value;
  right_value_expr.get_tuple_cell(value);

  const TupleCell *left_cell = nullptr;
  const TupleCell *right_cell = nullptr;
  bool left_inclusive = false;
  bool right_inclusive = false;

  switch (comp) {
  case EQUAL_TO: {
    left_cell = &value;
    right_cell = &value;
    left_inclusive = true;
    right_inclusive = true;
  } break;

  case LESS_EQUAL: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = true;
  } break;

  case LESS_THAN: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = false;
  } break;

  case GREAT_EQUAL: {
    left_cell = &value;
    left_inclusive = true;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  case GREAT_THAN: {
    left_cell = &value;
    left_inclusive = false;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  default: {
    LOG_WARN("should not happen. comp=%d", comp);
  } break;
  }

  IndexScanOperator *oper = new IndexScanOperator(table, index,
       left_cell, left_inclusive, right_cell, right_inclusive);

  LOG_INFO("use index for scan: %s in table %s", index->index_meta().name(), table->name());
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
    return RC::UNIMPLENMENT;;
  }
  
  if (rc != RC::SUCCESS || magic_table == nullptr) {
    LOG_ERROR("select result to a tuple set failed.");
    return rc;
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
  Operator *scan_oper = try_to_create_index_scan_operator(select_stmt->filter_stmt());
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

  RC rc = table->create_index(nullptr, create_index.index_name, create_index.attribute_name);
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
*/

RC ExecuteStage::do_update(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Trx *trx = session->current_trx();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();
  UpdateStmt *update_stmt = (UpdateStmt *)(sql_event->stmt());
  Operator *scan_oper = try_to_create_index_scan_operator(update_stmt->filter_stmt());
  if (nullptr == scan_oper) {
    scan_oper = new TableScanOperator(update_stmt->table());
  }

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
