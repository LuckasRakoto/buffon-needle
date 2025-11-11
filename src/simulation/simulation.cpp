#include "glad/gl.h"
#include "simulation/simulation.h"
#include "editor/editor.h"
#include <chrono>
#include <memory>
#include <GLFW/glfw3.h>
#include <thread>

constinit int WIDTH = 1200;
constinit int HEIGHT = 800;

void Simulation::start() {
  window =
      std::shared_ptr<Window>(new Window(WIDTH, HEIGHT, "Buffon's needle"));
  editor = std::unique_ptr<Editor>(new Editor(window));

  targetFrameDuration = std::chrono::duration<double>(1.0f / editor->speed);

  auto lastFrame = std::chrono::steady_clock::now();
  while (window->isOpen()) {
    auto now = std::chrono::steady_clock::now();
    auto delta = now - lastFrame;
    if (delta >= targetFrameDuration) {
      window->render([this]() { renderLoop(); });
      lastFrame = now;
    } else {
      std::this_thread::sleep_for(targetFrameDuration - delta);
    }
  }
}

void Simulation::renderLoop() {
  editor->render();
  targetFrameDuration = std::chrono::duration<double>(1.0f / editor->speed);
}
