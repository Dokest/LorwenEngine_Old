#include "VertexBuffer.h"

#include <stdlib.h>

namespace Lorwen { namespace Graphics {

	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	
	VertexBuffer::VertexBuffer(unsigned int bufferSize, GLenum drawType)
	{
		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, bufferSize, nullptr, drawType);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_BufferID);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


	void VertexBuffer::BufferData(int bufferSize, const void* data, GLenum drawType)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ARRAY_BUFFER, bufferSize, data, drawType);
	}

} }