#version 330 core
out vec4 FragColor;
in vec3 StickColor;

void main()
{
  FragColor = StickColor;
}
