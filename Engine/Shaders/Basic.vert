#version 330 core

layout (location = 0) in vec2 vertex; // <vec2 position>

uniform mat4 mvp = mat4(1.0);

void main()
{
    gl_Position = mvp * vec4(vertex.xy, 0.0, 1.0);
}