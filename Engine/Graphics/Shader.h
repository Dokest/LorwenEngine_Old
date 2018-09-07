#pragma once

#include <string>

#include "Maths/Maths.h"

using namespace Maths;

class Shader
{
private:
	unsigned int m_ShaderID = 0;

public:
	Shader() {}

	Shader& Use();

	void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr); // Note: Geometry shader is optional

	void SetFloat(const char* name, float value);
	void SetInteger(const char* name, int value);
	void SetVector2f(const char* name, const Vec2& value);
	void SetVector3f(const char* name, const Vec3& value);
	void SetVector4f(const char* name, const Vec4& value);
	void SetMatrix4(const char* name, const Mat4& value);

	void CheckCompileErrors(unsigned int object, std::string type);

public:
	inline unsigned int GetShaderID() { return m_ShaderID; }
};
