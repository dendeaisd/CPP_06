#pragma once

#include <string>

struct Data {
  int number;
  std::string name;
  float value;

  Data();
  Data(int nb, std::string nm, float val);
  Data(const Data &other);
  Data &operator=(const Data &other);
	~Data();
};