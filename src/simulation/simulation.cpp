#include "glad/gl.h"
#include "simulation/simulation.h"
#include "editor/editor.h"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>
#include <ostream>
#include <thread>
#include <shader/shader.h>

constinit const int WIDTH = 1200;
constinit const int HEIGHT = 800;
constexpr float STICK_LENGTH = 0.1f;

Simulation::Simulation()
    : sticks({}), stick_factory(StickFactory(STICK_LENGTH)) {
  window = std::make_unique<Window>(WIDTH, HEIGHT, "Buffon's needles");
  editor = std::make_unique<Editor>();
  editor->init(*window);
  unsigned int vbo, vao, ebo;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);
  sticks_vbo = vbo;
  sticks_vao = vao;
  sticks_ebo = ebo;
  stick_shader_program =
      std::unique_ptr<Shader>(new Shader(std::string("../shaders/stick.vert"),
                                         std::string("../shaders/stick.frag")));
}

void Simulation::start() {

  target_frame_duration = std::chrono::duration<double>(1.0f / editor->speed);

  auto lastFrame = std::chrono::steady_clock::now();
  while (window->isOpen()) {
    auto now = std::chrono::steady_clock::now();
    auto delta = now - lastFrame;
    if (delta >= target_frame_duration) {
      Stick s = stick_factory.new_stick();
      std::cout << s.to_string() << std::endl;
      sticks.push_back(s);
      window->render([this]() { render_loop(); });
      lastFrame = now;
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
  std::vector<float> vertices;
  std::vector<int> indices;

  for (const auto &stick : sticks) {
    vertices.append_range(stick.vertices);
    indices.append_range(stick.indices);
  }

  glBindVertexArray(sticks_vao);
  glBindBuffer(GL_ARRAY_BUFFER, sticks_vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sticks_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int),
               indices.data(), GL_STATIC_DRAW);

  int stride = 6 * sizeof(float);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride,
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glUseProgram(stick_shader_program->ID);

  glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

  glBindVertexArray(0);
}
