#pragma once

#include <string>

struct Data {
	Data(int n, std::string nm, float val) : number(n), name(nm), value(val) {}
	int number;
	std::string name;
	float value;
};