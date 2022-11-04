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
// Created by Wangyunlai on 2022/07/08.
//

#include "sql/operator/index_scan_operator.h"
#include "storage/index/index.h"

IndexScanOperator::IndexScanOperator(const Table *table, Index *index,
		    const char *&left_user_key, bool left_inclusive,
		    const char *&right_user_key, bool right_inclusive,
        int *attr_len, int attr_num)
  : table_(table), index_(index),
    left_inclusive_(left_inclusive), right_inclusive_(right_inclusive),
    attr_num_(attr_num)
{ 
  int total_len = 0;
  for (int i = 0 ; i < attr_num ; ++ i) {
    attr_len_[i] = attr_len[i];
    total_len += attr_len[i];
  }

  if (left_user_key) {
    left_user_key_ = (char*)malloc(total_len);
    memcpy(left_user_key_, left_user_key, total_len);
    LOG_INFO("left_user_key is not nullptr");

    // LOG_INFO("left_user_key_ =  %d", *(int*)left_user_key_);
    // LOG_INFO("left_user_key =  %d", *(int*)left_user_key);
    // LOG_INFO("left_user_key pointer = %p", left_user_key);
  } else {
    left_user_key_ = nullptr;
  }
  
  if (right_user_key) {
    right_user_key_ = (char*)malloc(total_len);
    memcpy(right_user_key_, right_user_key, total_len);
    LOG_INFO("right_user_key is not nullptr");

    // LOG_INFO("right_user_key_ =  %d", *(int*)right_user_key_);
    // LOG_INFO("right_user_key =  %d", *(int*)right_user_key);
    // LOG_INFO("right_user_key pointer = %p", right_user_key);
  } else {
    right_user_key_ = nullptr;
  }
}

IndexScanOperator::~IndexScanOperator()
{
  if (left_user_key_) {
    free(left_user_key_);
    left_user_key_ = nullptr;
  }
  if (right_user_key_) {
    free(right_user_key_);
    right_user_key_ = nullptr;
  }
}

RC IndexScanOperator::open()
{
  if (nullptr == table_ || nullptr == index_) {
    return RC::INTERNAL;
  }

  
  IndexScanner *index_scanner = index_->create_scanner(left_user_key_, attr_len_, attr_num_, left_inclusive_, right_user_key_, attr_len_, attr_num_, right_inclusive_);
  if (nullptr == index_scanner) {
    LOG_WARN("failed to create index scanner");
    return RC::INTERNAL;
  }

  record_handler_ = table_->record_handler();
  if (nullptr == record_handler_) {
    LOG_WARN("invalid record handler");
    index_scanner->destroy();
    return RC::INTERNAL;
  }
  index_scanner_ = index_scanner;

  tuple_.set_schema(table_, table_->table_meta().field_metas());
  
  return RC::SUCCESS;
}

RC IndexScanOperator::next()
{
  RID rid;
  RC rc = index_scanner_->next_entry(&rid);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return record_handler_->get_record(&rid, &current_record_);
}

RC IndexScanOperator::close()
{
  index_scanner_->destroy();
  index_scanner_ = nullptr;
  return RC::SUCCESS;
}

Tuple * IndexScanOperator::current_tuple()
{
  tuple_.set_record(&current_record_);
  return &tuple_;
}
