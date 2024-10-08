#pragma once

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
  Serializer() = delete;
  Serializer(const Serializer &) = delete;
  Serializer &operator=(const Serializer &) = delete;
  ~Serializer() {}

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};