#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <string>
#include <sstream>
#include <regex>
#include "rc.h"
#include "sql/parser/parse_defs.h"

inline char * integer_to_string(int val)
{
  return (char *)std::to_string(val).c_str();
}

inline char * float_to_string(float val)
{
  auto res = std::to_string(val);
  const std::string format("$1");
  try {
    std::regex r("(\\d*)\\.0{6}|");
    std::regex r2("(\\d*\\.{1}0*[^0]+)0*");
    res = std::regex_replace(res, r2, format);
    res = std::regex_replace(res, r, format);
  }
  catch (const std::exception & e) {
    return (char *)res.c_str();
  }
  return (char *)res.c_str();
}

inline int32_t float_to_integer(float val)
{
  return round(val);
}

inline float integer_to_float(int32_t val)
{
  return (float)val;
}

inline float string_to_float(const char * val)
{
  std::string str(val);
  bool point = false;
  int i = 0;
  for (; i < str.length(); ++i) {
    if (!isdigit(str[i])) {
      if (str[i] == '.') {
        if (!point) {
          point = true;
        } else {
          break;
        }
      }
    }
  }
  if (i == 0) {
    return 0;
  } else {
    return atof(str.substr(0, i).c_str());
  }
}

inline int32_t string_to_integer(const char * val)
{
  return float_to_integer(string_to_float(val));
}
