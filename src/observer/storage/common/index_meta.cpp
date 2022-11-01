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
// Created by Meiyi & Wangyunlai.wyl on 2021/5/18.
//

#include "storage/common/index_meta.h"
#include "storage/common/field_meta.h"
#include "storage/common/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "rc.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_TYPE("type");
const static Json::StaticString FIELD_FIELD_NAME("field_name");

RC IndexMeta::init(const char *name, const std::vector<const FieldMeta *> &fields_meta, IndexType type) {
  if (nullptr == name || common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  type_ = type;
  for(const FieldMeta * field_meta : fields_meta) {
    field_.push_back(field_meta->name());
  }
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  std::string fields = "";
  for (int i = 0 ; i < field_.size() ; ++ i) {
    if (i != 0) {
      fields += ",";
    }
    fields += field_[i];
  }

  json_value[FIELD_NAME] = name_;
  json_value[FIELD_FIELD_NAME] = fields;
  json_value[FIELD_TYPE] = int(type_);
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_value = json_value[FIELD_FIELD_NAME];
  const Json::Value &type = json_value[FIELD_TYPE];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!type.isInt()) {
    LOG_ERROR("Type is not a int. json value=%s", type.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!field_value.isString()) {
    LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
        name_value.asCString(),
        field_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  std::string fields(field_value.asCString());
  std::vector<const FieldMeta *> field_metas;
  std::string field = "";
  for(int i = 0 ; i < fields.length() ; ++ i) {
    if(fields[i] == ',') {
      const FieldMeta *field_meta = table.field(field.c_str());
      if (nullptr == field_meta) {
        LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }
      field_metas.push_back(field_meta);
      field = "";
      continue;
    }

    field += fields[i];
  }

  if (field != "") {
    const FieldMeta *field_meta = table.field(field.c_str());
    if (nullptr == field_meta) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field.c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }
    field_metas.push_back(field_meta);
  }

  return index.init(name_value.asCString(), field_metas, IndexType(type.asInt()));
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

const std::vector<std::string>& IndexMeta::fields() const {
  return field_;
}

const IndexType IndexMeta::type() const {
  return type_;
}

void IndexMeta::desc(std::ostream &os) const
{
  std::string fields = "";
  for (int i = 0 ; i < field_.size() ; ++ i) {
    if (i != 0) {
      fields += ",";
    }
    fields += field_[i];
  }
  os << "index name=" << name_ << ", field=" << fields;
}