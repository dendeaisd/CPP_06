#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./convert <literal>" << std::endl;
    return 1;
  }

  const std::string literal = argv[1];
  ScalarConverter::convert(literal);

  return 0;
}
