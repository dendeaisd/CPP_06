#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  Data originalData(42, "Test Data", 3.14f);

  std::cout << "Original Data:" << std::endl;
  std::cout << "Number: " << originalData.number << std::endl;
  std::cout << "Name: " << originalData.name << std::endl;
  std::cout << "Value: " << originalData.value << std::endl;

  uintptr_t serialized = Serializer::serialize(&originalData);
  std::cout << "Serialized uintptr_t value: " << serialized << std::endl;

  Data *deserializedData = Serializer::deserialize(serialized);

  std::cout << "\nDeserialized Data:" << std::endl;
  std::cout << "Number: " << deserializedData->number << std::endl;
  std::cout << "Name: " << deserializedData->name << std::endl;
  std::cout << "Value: " << deserializedData->value << std::endl;

  if (deserializedData == &originalData) {
    std::cout
        << "\nSuccess! The deserialized pointer matches the original pointer."
        << std::endl;
  } else {
    std::cout << "\nFailure! The deserialized pointer does not match the "
                 "original pointer."
              << std::endl;
  }

  return 0;
}
