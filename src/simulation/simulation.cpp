#include "glad/gl.h"
#include "simulation/simulation.h"
#include "editor/editor.h"
#include <memory>
#include <GLFW/glfw3.h>

void Simulation::start() {
  window =
    std::shared_ptr<Window>(new Window(WIDTH, HEIGHT, "Buffon's needle"));
  editor = std::unique_ptr<Editor>(new Editor(window));
  window->render([this]() { renderLoop(); });
}

void Simulation::renderLoop() {
  glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
  glClear(GL_COLOR_BUFFER_BIT);
  editor->render();
}
