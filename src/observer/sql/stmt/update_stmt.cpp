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

#include "sql/stmt/update_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"


UpdateStmt::UpdateStmt(Table *table, FilterStmt *filter_stmt)
  : table_ (table), filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, const Updates &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name;
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", 
             db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));
  //printf("debug info, update==NULL?%d\n", update == NULL);
  // Condition c = update.conditions[0];
  // printf("debug info, condition[0], left_attr:%s\n", c.left_attr.attribute_name);
  // printf("debug info, condition[0], right_attr:%s\n", c.right_attr.attribute_name);
  // for(int i = 0; i < update.condition_num; i++){
  //   printf("debug info, condition[%d], left_attr:%s, right_attr:%s\n", i, update.conditions[i].left_attr.attribute_name, update.conditions[i].right_attr.attribute_name);
  // }

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, &table_map,
			     update.conditions, update.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    rc = RC::SUCCESS;
    // 不返回错误，后续可能会对conditon做转化
    //return rc;
  }
  std::vector<SetValue> value_list(update.update_num);
  for(int i = update.update_num-1; i >= 0; i--){
    value_list[update.update_num - i - 1] = update.value_list[i];
  }

  UpdateStmt* update_stmt = new UpdateStmt(table, filter_stmt);
  update_stmt->set_value_list(value_list);
  update_stmt->set_conditions(update.conditions, update.condition_num);
  stmt = update_stmt;
  return rc;
}

RC UpdateStmt::update_filter(Db *db){
  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_->name()), table_));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table_, &table_map,
			     conditions_, condition_num_, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  filter_stmt_ = filter_stmt;
  return rc;
}
