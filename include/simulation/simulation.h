#include "editor/editor.h"
#include "window/window.h"
#include <memory>
class Simulation {
public:
  void start();

private:
  void renderLoop();

  std::unique_ptr<Editor> editor;
  std::shared_ptr<Window> window;
};
