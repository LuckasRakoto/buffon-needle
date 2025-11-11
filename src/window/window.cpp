#include <functional>
#include <glad/gl.h>
#include "GLFW/glfw3.h"
#include <memory>
#include <window/window.h>
#include <color/color.h>

void Window::loadGL() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

Window::Window(int width, int height, std::string title) {
  loadGL();
  window = std::shared_ptr<GLFWwindow>(
    glfwCreateWindow(width, height, title.c_str(), NULL, NULL),
    [](GLFWwindow *w) {
      if (w) {
        glfwDestroyWindow(w);
        glfwTerminate();
      }
    });

  glfwMakeContextCurrent(window.get());
  gladLoaderLoadGL();

  glfwSetFramebufferSizeCallback(window.get(), framebufferSizeCallback);
}

void Window::framebufferSizeCallback(GLFWwindow *_, int w, int h) {
  glViewport(0, 0, w, h);
}

void Window::render(std::function<void()> f) {
  while (!glfwWindowShouldClose(window.get())) {
    glfwPollEvents();

    background();

    f();

    glfwSwapBuffers(window.get());
  }
  window.reset();
}

bool Window::isOpen() {
  return window.get() && !glfwWindowShouldClose(window.get());
}

GLFWwindow *Window::getNativeWindow() {
  return window.get();
}

void Window::background() {
  glClearColor(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1], BACKGROUND_COLOR[2],
               1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}
