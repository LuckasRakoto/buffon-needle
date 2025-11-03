#pragma once

#include "window/window.h"
#include <memory>
#include <vector>

class Editor {
public:
  Editor(std::shared_ptr<Window> window);
  ~Editor();

  void render();

private:
  bool my_tool_active;
  std::vector<float> *my_color;
};
