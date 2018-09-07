#pragma once

#include <GL/glew.h>


class Texture2D
{
private:
	unsigned int m_TextureID;
	unsigned int m_Width, m_Height;

public:
	unsigned int InternalFormat, ImageFormat;

	unsigned int Wrap_S, Wrap_T;

	unsigned int FilterMin, FilterMax;

public:
	Texture2D();

	void GenerateTextureFromData(unsigned int width, unsigned int heigth, unsigned char* data);

	void Bind() const;

public:
	inline unsigned int& GetTextureID() { return m_TextureID; }

};
