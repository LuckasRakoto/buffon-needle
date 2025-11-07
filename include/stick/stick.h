#pragma once
#include <vector>

struct Position {
  float x;
  float y;
  float z;
};

class Stick {
public:
  Stick(Position start, Position end);
  std::vector<float> vertices;
};
