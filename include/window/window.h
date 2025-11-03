#pragma once
#include <string>

const int WIDTH = 1200;
const int HEIGHT = 800;

class Window {
private:
  int width;
  int height;
  std::string title;

  void loadGL();

public:
  Window(int w, int h, std::string title);
};
