#pragma once

#include "BaseBuffer.h"


class IndexBuffer : public BaseBuffer
{
private:
	unsigned int m_Count;
public:
	IndexBuffer() {}

	void Generate(const void* data, unsigned int count, GLenum DrawType = GL_STATIC_DRAW);
	virtual void Delete() const;

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count; }
};
