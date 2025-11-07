#include "stick/stick.h"
#include <glad/gl.h>
#include <vector>

Stick::Stick(Position *start, Position *end) {
  vertices = {start->x, start->y, start->z, end->x, end->y, end->z};
}
