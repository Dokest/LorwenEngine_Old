#version 330 core

layout (location = 0) in vec2 vertex;
layout (location = 1) in vec4 tint;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;
out vec4 Tint;

uniform mat4 pr_matrix;

void main()
{
	TexCoords = texCoords;
	Tint = tint;

	gl_Position = pr_matrix * vec4(vertex.xy, 0.0f, 1.0f);
}