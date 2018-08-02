#include "Shader.h"


namespace Lorwen { namespace Graphics {

	Shader& Shader::Use()
	{
		glUseProgram(m_ShaderID);
		return *this;
	}

	void Shader::Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource /*= nullptr*/)
	{
		unsigned int vertexID, fragmentID, geometryID;

		// Vertex Shader
		vertexID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexID, 1, &vertexSource, NULL);
		glCompileShader(vertexID);
		CheckCompileErrors(vertexID, "VERTEX");

		

		// Fragment Shader
		fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentID, 1, &fragmentSource, NULL);
		glCompileShader(fragmentID);
		CheckCompileErrors(fragmentID, "FRAGMENT");

		// Geometry Shader
		if (geometrySource != nullptr)
		{
			geometryID = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(geometryID, 1, &geometrySource, NULL);
			glCompileShader(geometryID);
			CheckCompileErrors(geometryID, "GEOMETRY");
		}

		// Shader
		m_ShaderID = glCreateProgram();

		glAttachShader(m_ShaderID, vertexID);
		glAttachShader(m_ShaderID, fragmentID);
		if (geometrySource != nullptr)
			glAttachShader(m_ShaderID, geometryID);

		glLinkProgram(m_ShaderID);

		CheckCompileErrors(m_ShaderID, "PROGRAM");

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
		if (geometrySource != nullptr)
			glDeleteShader(geometryID);

	}

	void Shader::SetFloat(const char* name, float value)
	{
		glUniform1f(glGetUniformLocation(m_ShaderID, name), value);
	}

	void Shader::SetInteger(const char* name, int value)
	{
		glUniform1i(glGetUniformLocation(m_ShaderID, name), value);
	}

	void Shader::SetVector2f(const char* name, const Vec2& value)
	{
		glUniform2f(glGetUniformLocation(m_ShaderID, name), value.x, value.y);
	}

	void Shader::SetVector3f(const char* name, const Vec3& value)
	{
		glUniform3f(glGetUniformLocation(m_ShaderID, name), value.x, value.y, value.z);
	}

	void Shader::SetVector4f(const char* name, const Vec4& value)
	{
		glUniform4f(glGetUniformLocation(m_ShaderID, name), value.x, value.y, value.z, value.w);
	}

	void Shader::SetMatrix4(const char* name, const Mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name), 1, GL_FALSE, value.Elements);
	}

	void Shader::CheckCompileErrors(unsigned int object, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(object, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(object, 1024, NULL, infoLog);
				std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
					<< infoLog << "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
		else
		{
			glGetProgramiv(object, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(object, 1024, NULL, infoLog);
				std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
					<< infoLog << "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
	}

} }