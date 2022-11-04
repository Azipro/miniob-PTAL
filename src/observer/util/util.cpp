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
// Created by wangyunlai on 2022/9/28
//

#include "common/log/log.h"
#include <string.h>
#include "util/util.h"

std::string double2string(double v)
{
  char buf[256];
  snprintf(buf, sizeof(buf), "%.2f", v);
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
      
  }
  if (buf[len - 1] == '.') {
    len--;
  }

  return std::string(buf, len);
}

bool is_match(std::string s, std::string p)
{
  if(p.empty())
    return s.empty();
  if(p[0] == '%')
    return (!s.empty() && is_match(s.substr(1), p)) || is_match(s, p.substr(1));
  else
    return !s.empty() && (s[0] == p[0] || p[0] == '_') && is_match(s.substr(1), p.substr(1));
}

bool like(const char * s, const char * p, int len)
{
  char str[255];
  strncpy(str, s, len);
  str[len] = '\0';
  return is_match(std::string(str), std::string(p));
}

bool is_number(const char * s)
{
  auto str = std::string(s);
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] < '0' || str[i] > '9') {
      return false;
    }
  }
  return true;
}

void null_data(void *&data, size_t bytes) { // 正确做法应该是用bitmap
  memset(data, (1 << 8) - 1, bytes);
}

bool is_null(const char *data, size_t len) {
  void *null_cell_data = malloc(len);
  null_data(null_cell_data, len);

  if (0 == strncmp((const char*)null_cell_data, data, len)) {
    free(null_cell_data);
    return true;
  }
  free(null_cell_data);
  return false;
}
