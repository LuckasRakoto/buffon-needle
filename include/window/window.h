#pragma once

#include <functional>

#include <memory>
#include <string>
#include <GLFW/glfw3.h>

struct Deletor {
  void operator()(GLFWwindow *w) const;
};

class Window {
private:
  std::unique_ptr<GLFWwindow, Deletor> window;

  void loadGL();

  static void framebufferSizeCallback(GLFWwindow *_, int w, int h);

  void background();

public:
  Window(int w, int h, std::string title);

  GLFWwindow *getNativeWindow();

  void render(std::function<void()> f);

  bool isOpen();
};
