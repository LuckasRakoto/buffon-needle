#include "window/window.h"

int main() {
  Window *w = new Window(WIDTH, HEIGHT, "Buffon's needle");
  w->render();
  delete w;
  return 0;
}
