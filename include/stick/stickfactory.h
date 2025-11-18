#include "stick/stick.h"
#include <utility>

class StickFactory {
public:
  StickFactory(float l);
  Stick new_stick();

private:
  std::pair<Position, Position> stick_start(float x, float y, float theta);
  std::pair<Position, Position> stick_end(float x, float y, float theta);
  float length;
};
