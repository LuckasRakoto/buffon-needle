#include <functional>
#include <glad/gl.h>
#include "GLFW/glfw3.h"
#include <memory>
#include <stdexcept>
#include <window/window.h>
#include <color/color.h>

void Deletor::operator()(GLFWwindow *w) const {
  if (w) {
    glfwDestroyWindow(w);
    glfwTerminate();
  }
}

void Window::loadGL() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, 4);
};

Window::Window(int width, int height, std::string title) {
  loadGL();
  window.reset(glfwCreateWindow(width, height, title.c_str(), NULL, NULL));

  auto window_ptr = window.get();
  if (!window_ptr) {
    throw std::runtime_error("Something happened at window creation");
  }
  glfwMakeContextCurrent(window_ptr);
  gladLoaderLoadGL();
  glEnable(GL_MULTISAMPLE);

  glfwSetFramebufferSizeCallback(window.get(), framebufferSizeCallback);
}

void Window::framebufferSizeCallback(GLFWwindow *_, int w, int h) {
  glViewport(0, 0, w, h);
}

void Window::render(std::function<void()> f) {
  glfwPollEvents();

  background();

  f();

  glfwSwapBuffers(window.get());
}

bool Window::isOpen() {
  return window.get() && !glfwWindowShouldClose(window.get());
}

GLFWwindow *Window::getNativeWindow() {
  return window.get();
}

void Window::background() {
  glClearColor(BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}
