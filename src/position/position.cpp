#include "position/position.h"
#include <array>
#include <print>

Position::Position(std::array<float, 3> pos) : x(pos[0]), y(pos[1]), z(pos[2]) {
}

std::array<float, 3> Position::unpack() const {
  return {x, y, z};
}

Position Position::offset_xy(float angle, float step) {
  return Position({
      x + step * cos(angle), //
      y + step * sin(angle), //
      z                      //
  });
}
