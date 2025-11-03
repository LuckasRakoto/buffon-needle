#pragma once

#include "window/window.h"
#include <memory>

class Editor {
public:
  Editor(std::shared_ptr<Window> window);
  ~Editor();

  void render();
};
