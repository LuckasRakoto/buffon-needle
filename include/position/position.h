#pragma once
#include <array>

class Position {
public:
  Position(std::array<float, 3> pos);
  std::array<float, 3> unpack() const;

  Position offset_xy(float angle, float step);

private:
  float x, y, z;
};
