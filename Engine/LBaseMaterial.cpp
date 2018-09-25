#include "LBaseMaterial.h"

#include "Graphics/ResourceManager.h"

class Shader& LBaseMaterial::SetShader(const std::string shaderName)
{
	m_pShader = &ResourceManager::GetShader(shaderName);

	return *m_pShader;
}

class Shader& LBaseMaterial::SetShader(const unsigned int shaderID)
{
	/* TODO */
	//ResourceManager::GetShader(shaderID);
}
