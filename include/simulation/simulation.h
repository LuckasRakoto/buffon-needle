#include "editor/editor.h"
#include "stick/stick.h"
#include "window/window.h"
#include "stick/stickfactory.h"
#include <chrono>
#include <memory>
#include "shader/shader.h"
#include <vector>

class Simulation {
public:
  void start();
  Simulation();

private:
  void render_loop();

  void render_sticks();

  std::vector<Stick> sticks;
  StickFactory stick_factory;
  unsigned int sticks_vao, sticks_vbo;
  std::unique_ptr<Shader> stick_shader_program;

  std::unique_ptr<Editor> editor;
  std::shared_ptr<Window> window;

  std::chrono::duration<double> target_frame_duration;
};
