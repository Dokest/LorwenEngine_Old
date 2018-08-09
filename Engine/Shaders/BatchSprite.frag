#version 330 core

out vec4 color;

in vec4 SpriteColor;

void main()
{
	color = SpriteColor;
}