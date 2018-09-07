#include "VertexBuffer.h"

#include <stdlib.h>

VertexBuffer::VertexBuffer(unsigned int bufferSize, GLenum drawType)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, nullptr, drawType);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VertexBuffer::Delete() const
{
	glDeleteBuffers(1, &m_BufferID);
}

void VertexBuffer::Generate(const void* data, unsigned int size)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::BufferData(int bufferSize, const void* data, GLenum drawType)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, data, drawType);
}
