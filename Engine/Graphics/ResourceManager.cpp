#include "ResourceManager.h"


#include <fstream>
#include <sstream>

#include <iostream>

#include <SOIL.h>

namespace Lorwen {

	std::map<std::string, Lorwen::Graphics::Shader> ResourceManager::Shaders;

	std::map<std::string, Lorwen::Graphics::Texture2D> ResourceManager::Textures;

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

		//std::cout << vertexCode.c_str() << std::endl;

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

		unsigned char* image = SOIL_load_image(file, &width, &height, 0, bAlpha == true ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
		std::cout << SOIL_last_result() << std::endl;

		texture.GenerateTextureFromData(width, height, image);

		SOIL_free_image_data(image);
		return texture;
	}

}