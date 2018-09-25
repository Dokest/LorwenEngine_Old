#pragma once

#include <string>

class LBaseMaterial
{
protected:
	unsigned int m_MaterialID;

	LBaseMaterial(const unsigned int materialID) 
		: m_MaterialID(materialID) {}

	class Shader* m_pShader;

public:


	unsigned int const GetMaterialID() const { return m_MaterialID; };

	class Shader& SetShader(const std::string shaderName);
	class Shader& SetShader(const unsigned int shaderID);
};

