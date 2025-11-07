#pragma once

#include <string>

class Shader {
public:
  unsigned int ID;
  Shader(std::string *vertexPath, std::string *fragmentPath);
  ~Shader();

private:
  unsigned int compileVertexShader(std::string *vertShaderSource);
  unsigned int compileFragmentShader(std::string *fragShaderSource);
  void buildProgram(unsigned int vertShader, unsigned int fragShader);

  void logShaderError(unsigned int shader);
};
