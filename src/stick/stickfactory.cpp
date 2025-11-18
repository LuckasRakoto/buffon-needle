#include "stick/stickfactory.h"
#include "position/position.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <numbers>
#include <utility>

const float HALF_STICK_WIDTH = 0.005f;
const float STICK_Z = 0.0f;

StickFactory::StickFactory(float l) : length(l) {
}

Stick StickFactory::new_stick() {
  counter++;
  float x = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
  float y = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
  float theta = (static_cast<float>(rand()) / RAND_MAX) * 2 * std::numbers::pi;

  return Stick(stick_start(x, y, theta), stick_end(x, y, theta), counter);
}

std::pair<Position, Position> StickFactory::stick_start(float x, float y,
                                                        float theta) {
  Position center = Position(
      {x + std::cos(theta) * length, y + std::sin(theta) * length, STICK_Z});
  return std::pair(
      center.offset_xy(theta + std::numbers::pi / 2, HALF_STICK_WIDTH),
      center.offset_xy(theta - std::numbers::pi / 2, HALF_STICK_WIDTH));
}

std::pair<Position, Position> StickFactory::stick_end(float x, float y,
                                                      float theta) {
  Position center = Position(
      {x - std::cos(theta) * length, y - std::sin(theta) * length, STICK_Z});
  return std::pair(
      center.offset_xy(theta + std::numbers::pi / 2, HALF_STICK_WIDTH),
      center.offset_xy(theta - std::numbers::pi / 2, HALF_STICK_WIDTH));
}
