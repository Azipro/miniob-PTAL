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
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include "rc.h"
#include "sql/stmt/stmt.h"
#include <vector>

class FieldMeta;
class FilterStmt;
class Db;
class Table;

class UpdateStmt : public Stmt
{
public:

  UpdateStmt() = default;
  UpdateStmt(Table *table, FilterStmt *filter_stmt);
  StmtType type() const override { return StmtType::UPDATE; }

public:
  static RC create(Db *db, const Updates &update_sql, Stmt *&stmt);

public:
  Table *table() const {return table_;}
  std::vector<SetValue> values_list() const { return value_list_; }
  int value_amount() const { return value_amount_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  void set_value_list(const std::vector<SetValue> &value_list) { value_list_ = value_list; }

private:
  std::vector<SetValue> value_list_;
  Table *table_ = nullptr;
  int value_amount_ = 0;
  FilterStmt *filter_stmt_ = nullptr;
};

