#include "Texture2D.h"

#include <iostream>

Texture2D::Texture2D()
	: m_Width(0), m_Height(0), InternalFormat(GL_RGB), ImageFormat(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), FilterMin(GL_LINEAR), FilterMax(GL_LINEAR)
{
	glGenTextures(1, &m_TextureID);
}

void Texture2D::GenerateTextureFromData(unsigned int width, unsigned int heigth, unsigned char* data)
{
	m_Width = width;
	m_Height = heigth;

	// Create Texture
	std::cout << "Internal format: " << (InternalFormat  == GL_RGBA) << " Image Format: " << (ImageFormat == GL_RGBA) << std::endl;
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, width, heigth, 0, ImageFormat, GL_UNSIGNED_BYTE, data);


	// Set Texture wrap & filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FilterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FilterMax);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}
