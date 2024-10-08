#include "Base.hpp"
#include "Derived.hpp"
#include <iostream>

Base *generate();
void identify(Base *p);
void identify(Base &p);

int main() {
  std::cout << "=== Identifying with Randomly Generated Instances ==="
            << std::endl;

  for (int i = 0; i < 3; ++i) {
    std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;

    Base *ptr = generate();

    std::cout << "Identifying using a pointer: ";
    identify(ptr);

    std::cout << "Identifying using a reference: ";
    identify(*ptr);

    delete ptr;
  }

  std::cout << "\n=== Manual Testing with Known Types ===" << std::endl;
  A a;
  B b;
  C c;

  Base *basePtr;

  /*Test with A*/
  basePtr = &a;
  std::cout << "\n--- Testing with A ---" << std::endl;
  std::cout << "Identifying using a pointer: ";
  identify(basePtr);
  std::cout << "Identifying using a reference: ";
  identify(*basePtr);

  /*Test with B*/
  basePtr = &b;
  std::cout << "\n--- Testing with B ---" << std::endl;
  std::cout << "Identifying using a pointer: ";
  identify(basePtr);
  std::cout << "Identifying using a reference: ";
  identify(*basePtr);

  /*Test with C*/
  basePtr = &c;
  std::cout << "\n--- Testing with C ---" << std::endl;
  std::cout << "Identifying using a pointer: ";
  identify(basePtr);
  std::cout << "Identifying using a reference: ";
  identify(*basePtr);

  std::cout << "\n=== End of Tests ===" << std::endl;

  return 0;
}
