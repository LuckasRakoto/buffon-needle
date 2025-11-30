#include "stick/stick.h"
#include <random>
#include <utility>

class StickFactory {
public:
  StickFactory(float l);
  Stick new_stick();

private:
  std::uniform_real_distribution<> dis;
  std::mt19937 gen;
  float random_float();

  std::pair<Position, Position> stick_start(float x, float y, float theta);
  std::pair<Position, Position> stick_end(float x, float y, float theta);
  float length;
  int counter = 0;
};
