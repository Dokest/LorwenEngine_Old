#pragma once

#include "BaseBuffer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Lorwen { namespace Graphics {

	class VertexArray : public BaseBuffer
	{
	private:


	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

		void Bind() const;
		void Unbind() const;
	};
} }

