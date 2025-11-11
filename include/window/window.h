#pragma once

#include <functional>

#include <memory>
#include <string>
#include <GLFW/glfw3.h>

class Window {
private:
  std::shared_ptr<GLFWwindow> window;

  void loadGL();

  static void framebufferSizeCallback(GLFWwindow *_, int w, int h);

  void background();

public:
  Window(int w, int h, std::string title);

  GLFWwindow *getNativeWindow();

  void render(std::function<void()> f);

  bool isOpen();
};
