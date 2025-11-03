#include <window/window.h>
#include "GLFW/glfw3.h"

void Window::loadGL() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

Window::Window(int w, int h, std::string title)
    : width(w), height(h), title(title) {
  glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
}
