#include "IndexBuffer.h"


void IndexBuffer::Generate(const void* data, unsigned int count, GLenum DrawType /*= GL_STATIC_DRAW*/)
{
	m_Count = count;

	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), (const void*)data, DrawType);
}

void IndexBuffer::Delete() const
{
	glDeleteBuffers(1, &m_BufferID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
