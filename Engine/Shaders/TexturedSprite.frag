#version 330 core

in vec2 TexCoords;
in vec4 Tint;

out vec4 color;

uniform sampler2D image;

void main()
{
	color = texture(image, TexCoords);

	if(color.a < 0.1)
		discard;

	color = Tint * color;
}