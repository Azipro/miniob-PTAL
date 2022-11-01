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
#include "common/log/log.h"

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
  void conditions(Condition *conditions) {
    for(int i = 0; i < condition_num_; i++){
      LOG_INFO("UpdateStmt: condition-%d, left_attr:%s, right_attr:%s", i, conditions_[i].left_attr.attribute_name, conditions_[i].right_attr.attribute_name);
      conditions[i] = conditions_[i];
    }
  }
  int condition_num(){return condition_num_;}
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  RC update_filter(Db *db);
  void set_value_list(const std::vector<SetValue> &value_list) { value_list_ = value_list; }
  void set_conditions(const Condition *conditions, int condition_num) {
    condition_num_ = condition_num;
    for(int i = 0; i < condition_num; i++){
      conditions_[i] = conditions[i];
    }
  }

private:
  std::vector<SetValue> value_list_;
  Condition conditions_[MAX_NUM];
  int condition_num_;
  Table *table_ = nullptr;
  FilterStmt *filter_stmt_ = nullptr;
};

