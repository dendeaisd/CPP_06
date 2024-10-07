#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>

static LiteralType detectType(const std::string &literal);
static bool isPseudoLiteral(const std::string &literal);
static void handlePseudoLiterals(const std::string &literal);

void ScalarConverter::convert(const std::string &literal) {
  LiteralType type = detectType(literal);

  if (type == LiteralType::UNKNOWN_TYPE) {
    std::cerr << "Error: Unknown literal type." << std::endl;
    return;
  }

  if (type == LiteralType::PSEUDO_LITERAL_TYPE) {
    handlePseudoLiterals(literal);
    return;
  }

  double value = 0.0;

  try {
    switch (type) {
    case LiteralType::CHAR_TYPE:
      value = static_cast<double>(literal[0]);
      break;
    case LiteralType::INT_TYPE:
      value = static_cast<double>(std::stoi(literal));
      break;
    case LiteralType::FLOAT_TYPE:
      value = static_cast<double>(std::stof(literal));
      break;
    case LiteralType::DOUBLE_TYPE:
      value = std::stod(literal);
      break;
    default:
      break;
    }
  } catch (const std::exception &e) {
    std::cerr << "Conversion error: " << e.what() << std::endl;
    return;
  }

  // convertToChar(value);
  // convertToInt(value);
  // convertToFloat(value);
  // convertToDouble(value);
}

static bool isPseudoLiteral(const std::string &literal) {
  return (literal == "nan" || literal == "nanf" || literal == "+inf" ||
          literal == "-inf" || literal == "+inff" || literal == "-inff");
}

static void handlePseudoLiterals(const std::string &literal) {
  std::string doubleLit = literal;

  if (literal.back() == 'f')
    doubleLit.pop_back();
  
	std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << literal << std::endl;
  std::cout << "double: " << doubleLit << std::endl;
}