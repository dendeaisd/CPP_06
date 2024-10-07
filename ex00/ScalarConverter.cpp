#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>

static LiteralType detectType(const std::string &literal);
static bool isPseudoLiteral(const std::string &literal);
static bool isCharLiteral(const std::string &literal);
static bool isIntLiteral(const std::string &literal);
static bool isFloatLiteral(const std::string &literal);
static bool isDoubleLiteral(const std::string &literal);
static void handlePseudoLiterals(const std::string &literal);
static void convertToChar(double value);
static void convertToInt(double value);
static void convertToFloat(double value);
static void convertToDouble(double value);

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

  convertToChar(value);
  convertToInt(value);
  convertToFloat(value);
  convertToDouble(value);
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

static void convertToChar(double value) {
  if (std::isnan(value) || std::isinf(value) ||
      value < static_cast<double>(std::numeric_limits<char>::min()) ||
      value > static_cast<double>(std::numeric_limits<char>::max())) {
    std::cout << "char: impossible" << std::endl;
  } else {
    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c)))
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  }
}

static void convertToInt(double value) {
  if (std::isnan(value) || std::isinf(value) ||
      value < static_cast<double>(std::numeric_limits<int>::min()) ||
      value > static_cast<double>(std::numeric_limits<int>::max())) {
    std::cout << "int: impossible" << std::endl;
  } else {
    int i = static_cast<int>(value);
    std::cout << "int: " << i << std::endl;
  }
}

static void convertToFloat(double value) {
  float f = static_cast<float>(value);
  if (std::isnan(f)) {
    std::cout << "float: nanf" << std::endl;
  } else if (std::isinf(f)) {
    if (std::signbit(f))
      std::cout << "float: -inff" << std::endl;
    else
      std::cout << "float: +inff" << std::endl;
  } else {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
              << std::endl;
  }
}

static void convertToDouble(double value) {
  if (std::isnan(value)) {
    std::cout << "double: nan" << std::endl;
  } else if (std::isinf(value)) {
    if (std::signbit(value))
      std::cout << "double: -inf" << std::endl;
    else
      std::cout << "double: +inf" << std::endl;
  } else {
    std::cout << "double: " << std::fixed << std::setprecision(1) << value
              << std::endl;
  }
}
