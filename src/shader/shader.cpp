#include "shader/shader.h"
#include "glad/gl.h"
#include <fstream>
#include <print>
#include <sstream>
#include <string>

Shader::Shader(std::string *vertexPath, std::string *fragmentPath) {
  std::string vertCode, fragCode;
  std::ifstream vertFile, fragFile;

  try {
    vertFile.open(vertexPath->c_str());
    fragFile.open(fragmentPath->c_str());
    std::stringstream vertStream;
    std::stringstream fragStream;
    vertStream << vertFile.rdbuf();
    fragStream << fragFile.rdbuf();
    vertFile.close();
    fragFile.close();
    vertCode = vertStream.str();
    fragCode = fragStream.str();
  } catch (std::ifstream::failure e) {
    std::println("ERROR:SHADER::FILE_NOT_SUCCESSFULLY_READ");
  }
  unsigned int fragmentShader = this->compileFragmentShader(&fragCode);
  unsigned int vertexShader = this->compileVertexShader(&vertCode);

  this->buildProgram(vertexShader, fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
};

Shader::~Shader() {
  glDeleteShader(this->ID);
}

unsigned int Shader::compileFragmentShader(std::string *fragShaderSource) {
  unsigned int fragmentShader;
  int success;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fragmentShaderSource = fragShaderSource->c_str();
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    this->logShaderError(fragmentShader);
  }
  return fragmentShader;
}
