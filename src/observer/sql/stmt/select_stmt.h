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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "storage/common/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

class SelectStmt : public Stmt
{
public:

  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }
public:
  static RC create(Db *db, const Selects &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const { return tables_; }
  const std::vector<Field> &query_fields() const { return query_fields_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  size_t agg_num() const { return agg_num_; }
  const std::vector<OrderField> &order_fields() const { return order_fields_; }
  const std::vector<GroupField> &group_fields() const { return group_fields_; }
  const std::vector<HavingField> &having_fields() const { return having_fields_; }

public:
  void set_query_fields(const std::vector<Field> &query_fields) { query_fields_ = query_fields; }
  void set_tables(const std::vector<Table *> &tables) { tables_ = tables; }
  void set_Filter(FilterStmt *const filter_stmt) { filter_stmt_ = filter_stmt; }
  void set_agg_num(size_t agg_num) { agg_num_ = agg_num; }
  void set_order_fields(const std::vector<OrderField> &order_fields) { order_fields_ = order_fields; }
  void set_group_fields(const std::vector<GroupField> &group_fields) { group_fields_ = group_fields; }
  void set_having_fields(const std::vector<HavingField> &having_fields) { having_fields_ = having_fields; }
  void set_conditions(const Condition *conditions, int condition_num) {
    condition_num_ = condition_num;
    for(int i = 0; i < condition_num; i++){
      conditions_[i] = conditions[i];
    }
  }
  int condition_num(){return condition_num_;}
  void conditions(Condition *conditions) {
    for(int i = 0; i < condition_num_; i++){
     conditions[i] = conditions_[i];
    }
  }
  RC update_filter(Db *db);

private:
  std::vector<Field> query_fields_;
  Condition conditions_[MAX_NUM];
  int condition_num_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  size_t agg_num_ = 0;
  std::vector<OrderField> order_fields_;
  std::vector<GroupField> group_fields_;
  std::vector<HavingField> having_fields_;
};

