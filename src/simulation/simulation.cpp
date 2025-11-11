#include "glad/gl.h"
#include "simulation/simulation.h"
#include "editor/editor.h"
#include <chrono>
#include <memory>
#include <GLFW/glfw3.h>
#include <numeric>
#include <thread>
#include <shader/shader.h>

constinit int WIDTH = 1200;
constinit int HEIGHT = 800;

Simulation::Simulation() : sticks({}), stick_factory(StickFactory(60)) {
  unsigned int vbo, vao;
  glGenBuffers(1, &vbo);
  glGenVertexArrays(1, &vao);
  sticks_vbo = vbo;
  sticks_vao = vao;
  stick_shader_program =
      std::unique_ptr<Shader>(new Shader(std::string("../shaders/stick.vert"),
                                         std::string("../shaders/stick.frag")));
}

void Simulation::start() {
  window =
      std::shared_ptr<Window>(new Window(WIDTH, HEIGHT, "Buffon's needle"));
  editor = std::unique_ptr<Editor>(new Editor(window));

  target_frame_duration = std::chrono::duration<double>(1.0f / editor->speed);

  auto lastFrame = std::chrono::steady_clock::now();
  while (window->isOpen()) {
    auto now = std::chrono::steady_clock::now();
    auto delta = now - lastFrame;
    if (delta >= target_frame_duration) {
      window->render([this]() { render_loop(); });
      lastFrame = now;
      sticks.push_back(stick_factory.new_stick());
    } else {
      std::this_thread::sleep_for(target_frame_duration - delta);
    }
  }
}

void Simulation::render_loop() {
  render_sticks();
  editor->render();
  target_frame_duration = std::chrono::duration<double>(1.0f / editor->speed);
}

void Simulation::render_sticks() {
  std::vector<float> vertices = std::accumulate(
      sticks.begin(), sticks.end(), std::vector<float>{},
      [](std::vector<float> acc, const Stick &s) {
        acc.insert(acc.end(), s.vertices.begin(), s.vertices.end());
        return acc;
      });
  glBindVertexArray(sticks_vao);

  glBindBuffer(GL_ARRAY_BUFFER, sticks_vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glEnableVertexAttribArray(0);

  glUseProgram(stick_shader_program->ID);
  glDrawArrays(GL_LINES, 0, vertices.size());

  glBindVertexArray(0);
}
