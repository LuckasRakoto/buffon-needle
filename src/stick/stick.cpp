#include "stick/stick.h"
#include <glad/gl.h>
#include <vector>
#include "color/color.h"

Stick::Stick(Position start, Position end) {
  vertices = {start.x,        start.y,        start.z,        STICKS_COLOR.r,
              STICKS_COLOR.g, STICKS_COLOR.b, end.x,          end.y,
              end.z,          STICKS_COLOR.r, STICKS_COLOR.g, STICKS_COLOR.b};
}
