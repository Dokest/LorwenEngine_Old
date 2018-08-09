#pragma once

#include "BaseBuffer.h"

namespace Lorwen { namespace Graphics {

	class IndexBuffer : public BaseBuffer
	{
	private:
		unsigned int m_Count;
	public:
		IndexBuffer(const void* data, unsigned int count, GLenum DrawType = GL_STATIC_DRAW);
		IndexBuffer() {}
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline unsigned int GetCount() const { return m_Count; }
	};
} }
