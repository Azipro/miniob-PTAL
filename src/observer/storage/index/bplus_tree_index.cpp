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
// Created by Meiyi & wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"
#include "common/log/log.h"

BplusTreeIndex::~BplusTreeIndex() noexcept
{
  close();
}

RC BplusTreeIndex::create(const char *file_name, const IndexMeta &index_meta, bool is_unique, const std::vector<const FieldMeta*> &fields_meta)
{
  if (inited_) {
    LOG_WARN("Failed to create index due to the index has been created before. file_name:%s, index:%s", file_name, index_meta.name());
    return RC::RECORD_OPENNED;
  }

  RC rc = Index::init(index_meta, fields_meta);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  rc = index_handler_.create(file_name, fields_meta, is_unique);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to create index_handler, file_name:%s, index:%s, rc:%s",
        file_name,
        index_meta.name(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully create index, file_name:%s, index:%s", file_name, index_meta.name());
  return RC::SUCCESS;
}

RC BplusTreeIndex::open(const char *file_name, const IndexMeta &index_meta, const std::vector<const FieldMeta*> &fields_meta)
{
  if (inited_) {
    LOG_WARN("Failed to open index due to the index has been initedd before. file_name:%s, index:%s",
        file_name,
        index_meta.name());
    return RC::RECORD_OPENNED;
  }

  RC rc = Index::init(index_meta, fields_meta);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  rc = index_handler_.open(file_name);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to open index_handler, file_name:%s, index:%s, rc:%s",
        file_name,
        index_meta.name(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully open index, file_name:%s, index:%s", file_name, index_meta.name());
  return RC::SUCCESS;
}

RC BplusTreeIndex::close()
{
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s", index_meta_.name());
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

IndexScanner *BplusTreeIndex::create_scanner(const char *left_user_key, int *left_len, int left_num, bool left_inclusive,
                          const char *right_user_key, int *right_len, int right_num, bool right_inclusive) {
  BplusTreeIndexScanner *index_scanner = new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_user_key, left_len, left_num, left_inclusive, right_user_key, right_len, right_num, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }

  return index_scanner;
}

// IndexScanner *BplusTreeIndex::create_scanner(const char *left_key, int left_len, bool left_inclusive,
// 					     const char *right_key, int right_len, bool right_inclusive)
// {
//   BplusTreeIndexScanner *index_scanner = new BplusTreeIndexScanner(index_handler_);
//   RC rc = index_scanner->open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
//   if (rc != RC::SUCCESS) {
//     LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
//     delete index_scanner;
//     return nullptr;
//   }
//   return index_scanner;
// }

RC BplusTreeIndex::sync()
{
  return index_handler_.sync();
}

char* BplusTreeIndex::construct_user_key(const char* record) {
  int key_len = 0;
  for(FieldMeta field : fields_meta_) {
    key_len += field.len();
  }
  char* user_key = (char*) malloc(key_len);
  int cur_pos = 0;
  for(FieldMeta field : fields_meta_) {
    memcpy(user_key + cur_pos, record + field.offset(), field.len());
    cur_pos += field.len();
  }
  return user_key;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid) {
  char* user_key = construct_user_key(record);
  RC rc = index_handler_.insert_entry(user_key, rid);
  free(user_key);
  return rc;
}

RC BplusTreeIndex::delete_entry(const char *record, const RID *rid) {
  char* user_key = construct_user_key(record);
  RC rc = index_handler_.delete_entry(user_key, rid);
  free(user_key);
  return rc;
}

// RC BplusTreeIndex::update_entry(const char *record, const RID *rid, const char *old_record) {
//   int key_len = 0;
//   for(FieldMeta field : fields_meta_) {
//     key_len += field.len();
//   }
//   char* new_user_key = construct_user_key(record);
//   char* old_user_key = construct_user_key(old_record);
//   if (0 == strncmp(new_user_key, old_user_key, key_len)){ // 相等, 无需操作
//     free(new_user_key);
//     free(old_user_key);
//     return RC::SUCCESS;
//   }

//   RC rc = index_handler_.update_entry(new_user_key, rid, old_user_key);
//   free(new_user_key);
//   free(old_user_key);
//   return rc;
// }

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler) : tree_scanner_(tree_handler)
{}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept
{
  tree_scanner_.close();
}

RC BplusTreeIndexScanner::open(const char *left_user_key, int *left_len, int left_num, bool left_inclusive,
                          const char *right_user_key, int *right_len, int right_num, bool right_inclusive)
{
  return tree_scanner_.open(left_user_key, left_len, left_num, left_inclusive,
                          right_user_key, right_len, right_num, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid)
{
  return tree_scanner_.next_entry(rid);
}

RC BplusTreeIndexScanner::destroy()
{
  delete this;
  return RC::SUCCESS;
}
