#include "Data.hpp"

Data::Data() : number(0), name(""), value(0.0f) {}

Data::Data(int n, std::string nm, float val)
    : number(n), name(nm), value(val) {}

Data::Data(const Data &other)
    : number(other.number), name(other.name), value(other.value) {}

Data &Data::operator=(const Data &other) {
  if (this != &other) {
    number = other.number;
    name = other.name;
    value = other.value;
  }
  return *this;
}
Data::~Data() {}
