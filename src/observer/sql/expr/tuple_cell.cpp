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
// Created by WangYunlai on 2022/07/05.
//

#include "sql/expr/tuple_cell.h"
#include "storage/common/field.h"
#include "common/log/log.h"
#include "util/comparator.h"
#include "util/util.h"
#include "util/date.h"
#include "util/typecast.h"

void TupleCell::to_string(std::ostream &os) const
{
  switch (attr_type_) {
  case INTS: {
    os << *(int *)data_;
  } break;
  case FLOATS: {
    float v = *(float *)data_;
    os << double2string(v);
  } break;
  case CHARS: {
    for (int i = 0; i < length_; i++) {
      if (data_[i] == '\0') {
        break;
      }
      os << data_[i];
    }
  } break;
  case DATES: {
    os << date_to_string(*(int *)data_);
  } break;
  case NULL_: {
    os << "NULL";
  } break;
  case TEXTS: {
    Text *text = (Text*) data_;
    os << text_to_string(text);
  } break;
  default: {
    LOG_WARN("unsupported attr type: %d", attr_type_);
  } break;
  }
}

int TupleCell::compare(const TupleCell &other) const
{
  if (this->attr_type_ == NULL_ || other.attr_type_ == NULL_) {
    return 0;
  }

  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
    case INTS: return compare_int(this->data_, other.data_);
    case FLOATS: return compare_float(this->data_, other.data_);
    case CHARS: return compare_string(this->data_, this->length_, other.data_, other.length_);
    case DATES: return compare_int(this->data_, other.data_);
    case TEXTS: {
      Text *t1 = (Text*)this->data_;
      Text *t2 = (Text*)other.data_;
      std::string text1 = text_to_string(t1);
      std::string text2 = text_to_string(t2);
      return compare_string((void*)text1.c_str(), t1->text_len, (void*)text2.c_str(), t2->text_len);
    }
    default: {
      LOG_WARN("unsupported type: %d", this->attr_type_);
    }
    }
  } else if (this->attr_type_ == INTS && other.attr_type_ == FLOATS) {
    float this_data = *(int *)data_;
    return compare_float(&this_data, other.data_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == INTS) {
    float other_data = *(int *)other.data_;
    return compare_float(data_, &other_data);
  } else if (this->attr_type_ == INTS && other.attr_type_ == CHARS) {
    float this_data = integer_to_float(*(int *)data_);
    float other_data = string_to_float(other.data_);
    return compare_float(&this_data, &other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == INTS) {
    float this_data = string_to_float(data_);
    float other_data = integer_to_float(*(int *)other.data_);
    return compare_float(&this_data, &other_data);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == CHARS) {
    float other_data = string_to_float(other.data_);
    return compare_float(data_, &other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == FLOATS) {
    float this_data = string_to_float(data_);
    return compare_float(&this_data, other.data_);
  } else if (this->attr_type_ == TEXTS && other.attr_type_ == CHARS) {
    Text *t = (Text*)this->data_;
    std::string text = text_to_string(t);
    return compare_string((void*)text.c_str(), t->text_len, other.data_, other.length_);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == TEXTS) {
    Text *t = (Text*)other.data_;
    std::string text = text_to_string(t);
    return compare_string(this->data_, this->length_, (void*)text.c_str(), t->text_len);
  } else if(other.attr_type_ == VALUELIST){
    ValueList* list = (ValueList*)other.data_;
    if(list != nullptr){
      for(int i = 0; i < list->length; i++){
        const TupleCell tmp(list->values[i].type, (char *)list->values[i].data);
        if(this->compare(tmp) == 0){
          return 0;
        }
      }
    }else{
      return -1;
    }
  }
  LOG_WARN("not supported");
  return -1; // TODO return rc?
}
