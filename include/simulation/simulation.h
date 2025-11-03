#include "editor/editor.h"
#include "stick/stick.h"
#include "window/window.h"
#include <memory>
#include <vector>

class Simulation {
public:
  void start();

private:
  void renderLoop();

  void renderSticks();

  std::unique_ptr<std::vector<Stick>> sticks;

  std::unique_ptr<Editor> editor;
  std::shared_ptr<Window> window;
};
