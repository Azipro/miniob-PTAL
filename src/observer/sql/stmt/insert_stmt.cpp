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

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "util/typecast.h"
#include "sql/parser/parse_defs.h"

InsertStmt::InsertStmt(Table *table, const Inserts_more* inserts, int inserts_amount)
  : table_ (table), inserts_(inserts), inserts_amount_(inserts_amount)
{}

RC InsertStmt::create(Db *db, const Inserts &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name;
  if (nullptr == db || nullptr == table_name || inserts.inserts_more_num <= 0) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, inserts_more_num=%d", 
             db, table_name, inserts.inserts_more_num);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check the fields number
  for (int i = 0 ; i < inserts.inserts_more_num ; ++ i) {
    const Value *values = inserts.inserts_more[i].values;
    const int value_num = inserts.inserts_more[i].value_num;
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num() - table_meta.sys_field_num();
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }

      // check fields type
    const int sys_field_num = table_meta.sys_field_num();
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type = values[i].type;
      if (field_type != value_type) { // TODO try to convert the value type to field type
        if (field_type == DATES) {
          int32_t date = -1;
          RC rc = string_to_date((char*)values[i].data, date);
          if (rc != RC::SUCCESS) {
            LOG_TRACE("string_to_date fail, data=%s", values[i].data);
            return rc;
          }
          value_destroy((Value*)&values[i]);
          value_init_date((Value*)&values[i], date);
          continue;
        } else if (field_type == INTS) {
          if (value_type == FLOATS) {
            int32_t val = -1;
            val = float_to_integer(*(float*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_integer((Value*)&values[i], val);
            continue;
          } else if (value_type == CHARS) {
            int32_t val = -1;
            val = string_to_integer((char*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_integer((Value*)&values[i], val);
            continue;
          }
        } else if (field_type == FLOATS) {
          if (value_type == INTS) {
            float val = -1;
            val = integer_to_float(*(int32_t*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_float((Value*)&values[i], val);
            continue;
          } else if (value_type == CHARS) {
            float val = -1;
            val = string_to_float((char*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_float((Value*)&values[i], val);
            continue;
          }
        } else if (field_type == CHARS) {
          if (value_type == INTS) {
            char * val = nullptr;
            val = integer_to_string(*(int32_t*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_string((Value*)&values[i], val);
            continue;
          } else if (value_type == FLOATS) {
            char * val = nullptr;
            val = float_to_string(*(float*)values[i].data);
            value_destroy((Value*)&values[i]);
            value_init_string((Value*)&values[i], val);
            continue;
          }
        }

        LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
                table_name, field_meta->name(), field_type, value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }

  }

  // everything alright
  stmt = new InsertStmt(table, inserts.inserts_more, inserts.inserts_more_num);
  return RC::SUCCESS;
}
