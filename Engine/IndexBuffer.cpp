#include "IndexBuffer.h"

namespace Lorwen { namespace Graphics {

	IndexBuffer::IndexBuffer(const void* data, unsigned int count, GLenum DrawType /*= GL_STATIC_DRAW*/)
		: m_Count(count)
	{
		glGenBuffers(1, &m_BufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), (const void*)data, DrawType);
	}

	IndexBuffer::~IndexBuffer()
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


} }