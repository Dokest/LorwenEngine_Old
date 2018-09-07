#include "VertexArray.h"

#include "DebugOpenGL.h"

#include <iostream>

VertexArray::VertexArray()
{
	//glGenVertexArrays(1, &m_BufferID);
}

VertexArray::VertexArray(const VertexArray& copy)
{
	
}

VertexArray::~VertexArray()
{

}

void VertexArray::Generate()
{
	glGenVertexArrays(1, &m_BufferID);
}

void VertexArray::Delete() const
{
	glDeleteVertexArrays(1, &m_BufferID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();

	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.Count, element.Type, element.Normalize, layout.GetStride(), (const void*)offset);

		offset += element.Count * VertexBufferElement::GetSizeOfType(element.Type);
	}

}

void VertexArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
