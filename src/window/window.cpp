#include <glad/gl.h>
#include "GLFW/glfw3.h"
#include <memory>
#include <window/window.h>

void Window::loadGL() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

Window::Window(int w, int h, std::string title)
    : width(w), height(h), title(title) {
  window = std::shared_ptr<GLFWwindow>(
    glfwCreateWindow(width, height, title.c_str(), NULL, NULL));

  glfwMakeContextCurrent(window.get());
  gladLoaderLoadGL();

  glfwSetFramebufferSizeCallback(window.get(), framebufferSizeCallback);
}

void Window::framebufferSizeCallback(GLFWwindow *_, int w, int h) {
  glViewport(0, 0, w, h);
}

void Window::render() {
}
