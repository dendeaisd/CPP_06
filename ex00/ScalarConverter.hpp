#pragma once

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &input);

private:
  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &) = delete;
  ScalarConverter &operator=(const ScalarConverter &) = delete;
  ~ScalarConverter() = delete;
};

enum class LiteralType {
  CHAR_TYPE,
  INT_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  PSEUDO_LITERAL_TYPE,
  UNKNOWN_TYPE
};
