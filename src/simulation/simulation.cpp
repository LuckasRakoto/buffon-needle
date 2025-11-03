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
  editor->render();
}
