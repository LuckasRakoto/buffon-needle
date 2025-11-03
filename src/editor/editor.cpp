#include "editor/editor.h"
#include "window/window.h"

#include <cmath>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <memory>
#include <vector>

Editor::Editor(std::shared_ptr<Window> window) {
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window.get()->getNativeWindow(), true);
  ImGui_ImplOpenGL3_Init("#version 330");
  my_color = new std::vector(4, 0.0f);
}

Editor::~Editor() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void Editor::render() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Edit Stick Spawn Speed", &editor_active,
               ImGuiWindowFlags_AlwaysAutoResize);
  ImGui::SliderInt("Speed", &speed, 1, 10);

  ImGui::End();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
