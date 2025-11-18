#pragma once
#include <array>

class Position {
public:
  std::array<float, 3> unpack() const;

private:
  float x, y, z;
};
