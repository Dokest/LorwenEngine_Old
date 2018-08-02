#pragma once

#include <map>
#include <string>

#include "Shader.h"
#include "Texture2D.h"

namespace Lorwen {

	using namespace Graphics;

	class ResourceManager
	{
	public:
		
		static std::map<std::string, Shader> Shaders;
		static std::map<std::string, Texture2D> Textures;

		static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
		static Shader& GetShader(std::string name);

		static Texture2D LoadTexture(const char* file, bool bAlpha, std::string name);
		static Texture2D& GetTexture(std::string name);

		static void Clear();

	private:
		ResourceManager() { }

		static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
		static Texture2D loadTextureFromFile(const char* file, bool bAlpha);

	};
}
