#pragma once

#include "window/window.h"
#include <memory>
#include <vector>

class Editor {
public:
  Editor(std::shared_ptr<Window> window);
  ~Editor();

  void render();

  int speed = 1;

private:
  bool editor_active = true;
};
