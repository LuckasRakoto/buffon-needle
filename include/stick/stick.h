#pragma once
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include "position/position.h"

class Stick {
public:
  Stick(std::pair<Position, Position> start, std::pair<Position, Position> end,
        int id);

  std::vector<int> indices;
  std::vector<float> vertices;

  std::string to_string() const {
    std::string s = "";
    std::for_each(indices.begin(), indices.end(), [&s](const auto &v) {
      s += std::to_string(v);
      s += ' ';
    });
    return s;
  };

private:
};
