#include <print>
#include "window/window.h"

int main() {
  Window *w = new Window(WIDTH, HEIGHT, "Buffon's needle");
  w->render();
  return 0;
}
