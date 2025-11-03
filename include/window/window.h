#pragma once

#include <functional>
const int WIDTH = 1200;
const int HEIGHT = 800;

#include <memory>
#include <string>
#include <GLFW/glfw3.h>

class Window {
private:
  int width;
  int height;
  std::string title;

  std::shared_ptr<GLFWwindow> window;

  void loadGL();

  static void framebufferSizeCallback(GLFWwindow *_, int w, int h);

public:
  Window(int w, int h, std::string title);
  ~Window();

  GLFWwindow *getNativeWindow();

  void render(std::function<void()> f);
};
