#pragma once
#include <utility>
#include <vector>
#include "position/position.h"

class Stick {
public:
  Stick(std::pair<Position, Position> start, std::pair<Position, Position> end);
  std::vector<float> vertices;
  std::vector<int> indices;
};
