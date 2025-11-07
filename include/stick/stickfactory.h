#include "stick/stick.h"

class StickFactory {
public:
  StickFactory(float l);
  Stick *newStick();

private:
  Position getStart(float x, float y, float theta);
  Position getEnd(float x, float y, float theta);
  float length;
};
