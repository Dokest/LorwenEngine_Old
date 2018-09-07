
#pragma once

#include <vector>

#include "GL/glew.h"

struct VertexBufferElement
{
	unsigned int Type;
	unsigned int Count;
	unsigned char Normalize;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		default:				return 0;
		}
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;


public:
	VertexBufferLayout()
		: m_Stride(0) {}

	template<typename>
	void Push(unsigned int count, bool bNormalize = GL_FALSE)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count, bool bNormalize)
	{
		m_Elements.push_back({ GL_FLOAT, count, bNormalize });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count, bool bNormalize)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, bNormalize });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count, bool bNormalize)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, bNormalize });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline unsigned int GetStride() const { return m_Stride; }
	inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

};