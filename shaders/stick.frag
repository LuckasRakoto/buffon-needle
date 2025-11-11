#version 330 core
layout (location = 0) in vec3 stickPos;
layout (location = 1) in vec3 sColor;

out vec4 StickColor;

void main()
{
  gl_Position = vec4(stickPos, 1.0);
  StickColor = vec4(sColor, 1.0);
}
