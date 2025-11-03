#include "window/window.h"
#include <memory>
class Simulation {
public:
  void Start();

private:
  std::unique_ptr<Window> window;
};
