#include "simulation/simulation.h"
#include <memory>

void Simulation::Start() {
  window =
    std::unique_ptr<Window>(new Window(WIDTH, HEIGHT, "Buffon's needle"));
  window->render();
}
