#include "position/position.h"
#include <print>

std::array<float, 3> Position::unpack() {
  return {x, y, z};
}
