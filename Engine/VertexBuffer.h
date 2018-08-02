#pragma once

#include "BaseBuffer.h"

namespace Lorwen { namespace Graphics {

	class VertexBuffer : public BaseBuffer
	{
	private:

	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
	};
} }
