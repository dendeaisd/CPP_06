#include "Base.hpp"
#include "Derived.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate() {
  static bool seeded = false;
  if (!seeded) {
    srand(static_cast<unsigned int>(time(0)));
    seeded = true;
  }
  int randNum = rand() % 3;

  switch (randNum) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    return nullptr;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != nullptr)
    std::cout << "Type is A" << std::endl;
  else if (dynamic_cast<B *>(p) != nullptr)
    std::cout << "Type is B" << std::endl;
  else if (dynamic_cast<C *>(p) != nullptr)
    std::cout << "Type is C" << std::endl;
  else
    std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Type is A" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Type is B" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Type is C" << std::endl;
    return;
  } catch (std::bad_cast &) {
  }
  std::cout << "Unknown Type" << std::endl;
}
