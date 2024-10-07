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