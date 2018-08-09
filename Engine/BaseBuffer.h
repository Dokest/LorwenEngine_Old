#pragma once

#include "GL/glew.h"

namespace Lorwen { namespace Graphics {

	class BaseBuffer
	{
	protected:
		unsigned int m_BufferID;

	public:
		BaseBuffer();
		~BaseBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		inline const unsigned int GetShaderID() const { return m_BufferID; }
	};
} }
