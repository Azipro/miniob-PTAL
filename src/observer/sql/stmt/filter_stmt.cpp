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

#include "rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "sql/parser/parse_defs.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		      const Condition *conditions, int condition_num,
		      FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		       const RelAttr &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name)) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(std::string(attr.relation_name));
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name);
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name);
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name);
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
				  const Condition &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;
  
  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  if (comp == OP_LIKE || comp == OP_NOT_LIKE) {
    if (condition.right_is_attr) {
      LOG_TRACE("right must be value");
      return RC::INVALID_ARGUMENT;
    }
    if (condition.left_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find left_attr ");
        return rc;
      }
      if (!((field->type() == AttrType::CHARS || field->type() == AttrType::TEXTS) && condition.right_value.type == AttrType::CHARS)) {
        LOG_INFO("left and right must be char");
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    } else {
      if (!(condition.left_value.type == AttrType::CHARS && condition.right_value.type == AttrType::CHARS)) {
        LOG_INFO("left and right must be char");
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }

  // 只能是is null 或 is not null
  if (condition.comp == EQUAL_IS || condition.comp == NOT_EQUAL_IS) {
    if (condition.right_is_attr || condition.right_value.type != NULL_) {
      LOG_ERROR("Must be \"is null or is not null\".");
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    
    // Table *table = nullptr;
    // const FieldMeta *field = nullptr;
    // rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
    // if (rc != RC::SUCCESS) {
    //   LOG_WARN("cannot find left_attr ");
    //   return rc;
    // }
    // if (!field->nullable()) {
    //   LOG_ERROR("%s.%s is not nullable.", table->name(), field->name());
    //   return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    // }
  }

  Expression *left = nullptr;
  Expression *right = nullptr;
  AttrType left_type = AttrType::UNDEFINED;
  AttrType right_type = AttrType::UNDEFINED;
  bool left_nullable = false;
  bool right_nullable = false;

  if (condition.left_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);  
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      return rc;
    }
    left = new FieldExpr(table, field);
    left_type = field->type();
    left_nullable = field->nullable();
  } else {
    left = new ValueExpr(condition.left_value);
    left_type = condition.left_value.type;
    left_nullable = condition.left_value.type == NULL_ ? true : false;
  }

  if (condition.right_is_attr) {
    Table *table = nullptr;
    const FieldMeta *field = nullptr;
    rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);  
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot find attr");
      delete left;
      return rc;
    }
    right = new FieldExpr(table, field);
    right_type = field->type();
    right_nullable = field->nullable();
  } else {
    right = new ValueExpr(condition.right_value);
    right_type = condition.right_value.type;
    right_nullable = condition.right_value.type == NULL_ ? true : false;
  }

  // check and transform date type
  if (condition.left_is_attr and left_type == DATES and !condition.right_is_attr and right_type != DATES) {
    if (condition.right_value.type == CHARS) {
      int32_t date = -1;
      RC rc = string_to_date((char*)condition.right_value.data, date);
      if (rc != RC::SUCCESS) {
        LOG_TRACE("string_to_date fail, data=%s", condition.right_value.data);
        return rc;
      }
      value_destroy((Value*)&condition.right_value);
      value_init_date((Value*)&condition.right_value, date);
      delete right;
      right = new ValueExpr(condition.right_value);
      right_type = condition.right_value.type;
    }
  } else if (!condition.left_is_attr and left_type != DATES and condition.right_is_attr and right_type == DATES) {
    if (condition.left_value.type == CHARS) {
      int32_t date = -1;
      RC rc = string_to_date((char*)condition.left_value.data, date);
      if (rc != RC::SUCCESS) {
        LOG_TRACE("string_to_date fail, data=%s", condition.left_value.data);
        return rc;
      }
      value_destroy((Value*)&condition.left_value);
      value_init_date((Value*)&condition.left_value, date);
      delete left;
      left = new ValueExpr(condition.left_value);
      left_type = condition.left_value.type;
    }
  }

  if (condition.left_is_attr && !left_nullable && right_type == NULL_) {
    LOG_ERROR("left field is not nullable.");
    return RC::INVALID_ARGUMENT;
  }
  if (condition.right_is_attr && !right_nullable && left_type == NULL_) {
    LOG_ERROR("right field is not nullable.");
    return RC::INVALID_ARGUMENT;
  }

  if (left_type == right_type || (left_type == DATES && right_type == NULL_) || (right_type == DATES && left_type == NULL_) || 
      (left_type == TEXTS && (right_type == CHARS || right_type == NULL_)) || (right_type == TEXTS && (left_type == CHARS || left_type == NULL_)) ||
      ((left_type == INTS || left_type == FLOATS || left_type == CHARS || left_type == NULL_) &&
          (right_type == INTS || right_type == FLOATS || right_type == CHARS || right_type == NULL_))) {
    filter_unit = new FilterUnit;
    filter_unit->set_comp(comp);
    filter_unit->set_left(left);
    filter_unit->set_right(right);
  } else {
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  // 检查两个类型是否能够比较
  return rc;
}
