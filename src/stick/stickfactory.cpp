#include "stick/stickfactory.h"
#include "position/position.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <numbers>
#include <random>
#include <utility>

const float HALF_STICK_WIDTH = 0.005f;
const float STICK_Z = 0.0f;

StickFactory::StickFactory(float l) : length(l) {
  std::random_device rd;
  gen = std::mt19937(rd);
  dis = std::uniform_real_distribution<>(-1.0, 1.0);
}

float StickFactory::random_float() {
  return dis(gen);
}

Stick StickFactory::new_stick() {
  counter++;
  float x = random_float();
  float y = random_float();
  float theta = (random_float() + 1) / 2 * std::numbers::pi;

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
