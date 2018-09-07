#pragma once

#include <map>
#include <string>

#include "Shader.h"
#include "Texture2D.h"

#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"

class ResourceManager
{
public:
	ResourceManager();

	static std::hash<std::string> m_Hasher;

	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture2D> Textures;

	static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
	static Shader& GetShader(std::string name);

	static Texture2D LoadTexture(const char* file, bool bAlpha, std::string name);
	static Texture2D& GetTexture(std::string name);

	static void Clear();


	/**
	 *  INDEX BUFFER
	 */
private:
	static std::map<unsigned int, IndexBuffer> m_IndexBuffers;

public:
	static IndexBuffer& LoadIndexBuffer(unsigned int* indices, unsigned int indexCount, const char* iBOName);
	static IndexBuffer& GetIndexBuffer(const char* iBOName);

	/**
	 *	VERTEX BUFFER
	 */
private:
	static std::map<unsigned int, VertexBuffer> m_VertexBuffers;

public:
	static VertexBuffer& LoadVertexBuffer(float* vertices, unsigned int size, const char* name);
	static VertexBuffer& GetVertexBuffer(const char* name);

	/**
	 *	VERTEX ARRAY
	 */
private:
	static std::map<unsigned int, VertexArray> m_VertexArrays;

public:
	static VertexArray& LoadVertexArray(const char* name);
	static VertexArray& GetVertexArray(const char* name);

private:
	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
	static Texture2D loadTextureFromFile(const char* file, bool bAlpha);

};
