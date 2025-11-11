#include "stick/stick.h"

class StickFactory {
public:
  StickFactory(float l);
  Stick new_stick();

private:
  Position getStart(float x, float y, float theta);
  Position getEnd(float x, float y, float theta);
  float length;
};
