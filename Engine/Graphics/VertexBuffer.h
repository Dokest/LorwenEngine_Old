#pragma once

#include "BaseBuffer.h"

namespace Lorwen { namespace Graphics {

	class VertexBuffer : public BaseBuffer
	{
	private:

	public:
		VertexBuffer();
		VertexBuffer(const void* data, unsigned int size);
		VertexBuffer(unsigned int bufferSize, GLenum drawType);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;

		void BufferData(int bufferSize, const void* data, GLenum drawType);
	};
} }
