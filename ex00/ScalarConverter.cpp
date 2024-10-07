#include "ScalarConverter.hpp"

#include <cmath>
#include <cstddef>
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

static bool isPseudoLiteral(const std::string &literal) {
  return (literal == "nan" || literal == "nanf" || literal == "+inf" ||
          literal == "-inf" || literal == "+inff" || literal == "-inff");
}

static bool isCharLiteral(const std::string &literal) {
  return (literal.length() == 1 &&
          std::isprint(static_cast<unsigned char>(literal[0])) &&
          !std::isdigit(static_cast<unsigned char>(literal[0])));
}

static bool isIntLiteral(const std::string &literal) {
  size_t pos = 0;
  try {
    int value = std::stoi(literal, &pos);
    (void)value; // Suppress unused variable warning
    return pos == literal.length();
  } catch (...) {
    return false;
  }
}

static bool isFloatLiteral(const std::string &literal) {
  if (literal.back() != 'f')
    return false;

  std::string floatPart = literal.substr(0, literal.length() - 1);
  size_t pos = 0;
  try {
    float value = std::stof(floatPart, &pos);
    (void)value;
    return pos == floatPart.length();
  } catch (...) {
    return false;
  }
}

static bool isDoubleLiteral(const std::string &literal) {
  size_t pos = 0;
  try {
    double value = std::stod(literal, &pos);
    (void)value;
    return pos == literal.length();
  } catch (...) {
    return false;
  }
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

static LiteralType detectType(const std::string &literal) {
  if (isPseudoLiteral(literal))
    return LiteralType::PSEUDO_LITERAL_TYPE;

  if (isCharLiteral(literal))
    return LiteralType::CHAR_TYPE;

  if (isIntLiteral(literal))
    return LiteralType::INT_TYPE;

  if (isFloatLiteral(literal))
    return LiteralType::FLOAT_TYPE;

  if (isDoubleLiteral(literal))
    return LiteralType::DOUBLE_TYPE;

  return LiteralType::UNKNOWN_TYPE;
}
