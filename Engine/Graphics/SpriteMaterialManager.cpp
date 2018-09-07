#include "SpriteMaterialManager.h"


std::map<unsigned int, SpriteMaterial> SpriteMaterialManager::m_Materials;
std::hash<std::string>SpriteMaterialManager::m_Hasher;

SpriteMaterial& SpriteMaterialManager::AddMaterial(const std::string materialName)
{
	unsigned int iD = m_Hasher(materialName);

	m_Materials[iD] = SpriteMaterial();
	m_Materials[iD].ID = iD;

	return m_Materials[iD];
}

SpriteMaterial& SpriteMaterialManager::GetMaterial(const std::string materialName)
{
	unsigned int iD = m_Hasher(materialName);

	return m_Materials.at(iD);
}

SpriteMaterial& SpriteMaterialManager::GetMaterial(const unsigned int materialID)
{
	return m_Materials.at(materialID);
}