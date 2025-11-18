#include "stick/stick.h"
#include <glad/gl.h>
#include <utility>
#include <vector>
#include "color/color.h"

Stick::Stick(std::pair<Position, Position> start,
             std::pair<Position, Position> end)
    : vertices({}), indices({}) {
  auto add_vertex = [&](const Position &p) {
    vertices.append_range(p.unpack());
    vertices.append_range(STICKS_COLOR.unpack());
  };
  add_vertex(start.first);
  add_vertex(start.second);
  add_vertex(end.first);
  add_vertex(end.second);

  auto indices = std::vector<unsigned int>{
      0, 1, 2, // 1st triangle
      2, 3, 1, // 2nd triangle
  };
  indices.append_range(indices);
}
