#pragma once

#include <string>

class Shader {
public:
  unsigned int ID;
  Shader(const char *vertexPath, const char *fragmentPath);
  ~Shader();

private:
  unsigned int compileVertexShader(std::string vertShaderSource);
  unsigned int compileFragmentShader(std::string fragShaderSource);
  void buildProgram(unsigned int vertShader, unsigned int fragShader);
};
