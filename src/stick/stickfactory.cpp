#include "stick/stickfactory.h"
#include <cmath>
#include <cstdlib>
#include <numbers>

StickFactory::StickFactory(float l) : length(l) {
}

Stick StickFactory::new_stick() {
  float x = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
  float y = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
  float theta = (static_cast<float>(rand()) / RAND_MAX) * 2 * std::numbers::pi;
  return Stick(getStart(x, y, theta), getEnd(x, y, theta));
}

Position StickFactory::getStart(float x, float y, float theta) {
  return {.x = x + std::cos(theta) * length,
          .y = y + std::sin(theta) * length,
          .z = 1.0f};
}

Position StickFactory::getEnd(float x, float y, float theta) {
  return {.x = x - std::cos(theta) * length,
          .y = y - std::sin(theta) * length,
          .z = 1.0f};
}
