#pragma once

#include <map>

#include "Maths/Maths.h"

#include "ResourceManager.h"

struct SpriteMaterial
{
	unsigned int ID;

	/* Material Attributes */
	Maths::Vec4 Tint;
	class Texture2D * Texture;

	class Shader* pShader;

	class IndexBuffer* pIBO;
	class VertexBuffer* pVBO;
	class VertexArray* pVAO;

	SpriteMaterial()
		: ID(0), Tint(Maths::Vec4(1.0f, 1.0f, 1.0f, 1.0f)), pShader(&ResourceManager::GetShader("DEFAULT"))
		, pIBO(&ResourceManager::GetIndexBuffer("DEFAULT")), pVBO(&ResourceManager::GetVertexBuffer("DEFAULT")), pVAO(&ResourceManager::GetVertexArray("DEFAULT")),
		Texture(&ResourceManager::GetTexture("DEFAULT"))
	{ }
};


class SpriteMaterialManager
{
private:
	static std::map<unsigned int, SpriteMaterial> m_Materials;
	static std::hash<std::string> m_Hasher;

public:

	SpriteMaterialManager()
	{
		AddMaterial("DEFAULT");
	}

	static SpriteMaterial& AddMaterial(const std::string materialName);

	static SpriteMaterial& GetMaterial(const std::string materialName);

	static SpriteMaterial& GetMaterial(const unsigned int materialID);

};