#pragma once

#include "GL/glew.h"


class BaseBuffer
{
protected:
	unsigned int m_BufferID;

public:
	BaseBuffer();
	~BaseBuffer();

	virtual void Bind() const;
	virtual void Unbind() const;
	virtual void Delete() const = 0;

	inline const unsigned int GetShaderID() const { return m_BufferID; }
};