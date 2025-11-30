#pragma once

#include "window/window.h"

class Editor {
public:
  Editor();

  void init(Window &w);

  ~Editor();

  void render();

  int speed = 1;

private:
  bool editor_active = true;
};
