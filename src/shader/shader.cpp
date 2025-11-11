#include "shader/shader.h"
#include <glad/gl.h>
#include <OpenGL/gl.h>
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
  int success;
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fragmentShaderSource = fragShaderSource->c_str();
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    this->logShaderError(fragmentShader);
    // TODO: Actually handle the error here
  }
  return fragmentShader;
}

unsigned int Shader::compileVertexShader(std::string *vertShaderSource) {
  int success;
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char *vertexShaderSource = vertShaderSource->c_str();
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    this->logShaderError(vertexShader);
    // TODO: Actually handle the error here
  }
  return vertexShader;
}

void Shader::buildProgram(unsigned int vertexShader,
                          unsigned int fragmentShader) {
  int success;
  char infolog[512];
  unsigned int program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program, 512, NULL, infolog);
    std::printf("ERROR::SHADER:PROGRAM::LINKAGE_FAILED:\n%s\n", infolog);
    // TODO: Actually handle the error here
  }
  ID = program;
}

void Shader::logShaderError(unsigned int _) {
  // TODO : IMPLEMENT THIS
}
