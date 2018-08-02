#pragma once

#include "BaseRenderable.h"

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace Lorwen { namespace Graphics {

	class SpriteRenderable : public BaseRenderable
	{
	public:
		VertexBuffer* VBO;
		IndexBuffer* IBO;

	public:
		SpriteRenderable();
		SpriteRenderable(VertexBuffer* vertexBuffer, IndexBuffer* indexBuffer);
		~SpriteRenderable();
	};
} }


