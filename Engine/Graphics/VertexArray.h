#pragma once

#include "BaseBuffer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray : public BaseBuffer
{
public:
	VertexArray();
	VertexArray(const VertexArray& copy);
	~VertexArray();

	void Generate();
	virtual void Delete() const;

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};

