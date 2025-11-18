#include "stick/stick.h"
#include <glad/gl.h>
#include <utility>
#include <vector>
#include "color/color.h"

Stick::Stick(std::pair<Position, Position> start,
             std::pair<Position, Position> end, int counter)
    : vertices({}) {
  auto add_vertex = [&](const Position &p) {
    vertices.append_range(p.unpack());
    vertices.append_range(STICKS_COLOR.unpack());
  };
  add_vertex(start.first);
  add_vertex(start.second);
  add_vertex(end.first);
  add_vertex(end.second);

  int base = (counter - 1) * 4;

  indices = std::vector<int>{
      0, 1, 2, // 1st triangle
      2, 3, 1, // 2nd triangle
  };
  std::transform(indices.begin(), indices.end(), indices.begin(),
                 [base](int &index) { return index + base; });

  indices.append_range(indices);
}
