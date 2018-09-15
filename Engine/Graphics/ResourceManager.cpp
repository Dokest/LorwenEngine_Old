#include "ResourceManager.h"


#include <fstream>
#include <sstream>

#include <iostream>

#include <SOIL.h>


std::hash<std::string> ResourceManager::m_Hasher;

std::map<std::string, Shader> ResourceManager::Shaders;

std::map<std::string, Texture2D> ResourceManager::Textures;

std::map<unsigned int, VertexArray> ResourceManager::m_VertexArrays;

std::map<unsigned int, IndexBuffer> ResourceManager::m_IndexBuffers;

std::map<unsigned int, VertexBuffer> ResourceManager::m_VertexBuffers;

ResourceManager::ResourceManager()
{
	LoadShader("../Engine/Shaders/TexturedSprite.vert", "../Engine/Shaders/TexturedSprite.frag", nullptr, "DEFAULT");

	unsigned int indices[6] =
	{
		0, 1, 2, 2, 3, 0
	};

	LoadIndexBuffer(indices, 6, "DEFAULT");

	float vertices[8] =
	{
		 1.0f,  1.0f,
		 1.0f,  1.0f,
		 1.0f, 1.0f,
		1.0f, 1.0f
	};

	LoadVertexBuffer(vertices, sizeof(float) * 8, "DEFAULT");

	LoadVertexArray("DEFAULT");

	LoadTexture("../Others/Textures/TransparencyCheck.png", true, "DEFAULT");
}


Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return Shaders[name];
}

Shader& ResourceManager::GetShader(std::string name)
{
	return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(const char* file, bool bAlpha, std::string name)
{
	Textures[name] = loadTextureFromFile(file, bAlpha);

	return Textures[name];
}

Texture2D& ResourceManager::GetTexture(std::string name)
{
	return Textures[name];
}

void ResourceManager::Clear()
{
	// (Properly) delete all shaders	
	for (auto iter : Shaders)
		glDeleteProgram(iter.second.GetShaderID());

	// (Properly) delete all textures
	for (auto iter : Textures)
		glDeleteTextures(1, &iter.second.GetTextureID());
}



IndexBuffer& ResourceManager::LoadIndexBuffer(unsigned int* indices, unsigned int indexCount, const char* iBOName)
{
	IndexBuffer indexBuffer;
	indexBuffer.Generate(indices, indexCount);

	return m_IndexBuffers[m_Hasher(iBOName)] = indexBuffer;
}

IndexBuffer& ResourceManager::GetIndexBuffer(const char* iBOName)
{
	return m_IndexBuffers.at(m_Hasher(iBOName));
}

VertexBuffer& ResourceManager::LoadVertexBuffer(float* vertices, unsigned int size, const char* name)
{
	VertexBuffer buffer;
	buffer.Generate(vertices, size);

	return m_VertexBuffers[m_Hasher(name)] = buffer;
}

VertexBuffer& ResourceManager::GetVertexBuffer(const char* name)
{
	return m_VertexBuffers.at(m_Hasher(name));
}

VertexArray& ResourceManager::LoadVertexArray(const char* name)
{
	VertexArray vertexArray = VertexArray();
	vertexArray.Generate();
	m_VertexArrays[m_Hasher(name)] = vertexArray;

	return m_VertexArrays[m_Hasher(name)];
}

VertexArray& ResourceManager::GetVertexArray(const char* name)
{
	return m_VertexArrays[m_Hasher(name)];
}

Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile /*= nullptr*/)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		// If geometry shader path is present, also load a geometry shader
		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}

	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();

	// 2. Now create shader object from source code
	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);

	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool bAlpha)
{
	// Create texture object
	Texture2D texture;
	if (bAlpha)
	{
		texture.InternalFormat = GL_RGBA;
		texture.ImageFormat = GL_RGBA;
	}

	// Load image
	int width, height;

	unsigned char* image = SOIL_load_image(file, &width, &height, 0, (bAlpha == true) ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	std::cout << SOIL_last_result() << std::endl;

	std::cout << image << std::endl;

	texture.GenerateTextureFromData(width, height, image);

	SOIL_free_image_data(image);
	return texture;
}
