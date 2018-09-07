#pragma once

#include "BaseBuffer.h"

class VertexBuffer : public BaseBuffer
{
private:

public:
	VertexBuffer(unsigned int bufferSize, GLenum drawType);
	VertexBuffer() {}

	void Bind() const;
	void Unbind() const;

	virtual void Delete() const;
	void Generate(const void* data, unsigned int size);

	void BufferData(int bufferSize, const void* data, GLenum drawType);
};
