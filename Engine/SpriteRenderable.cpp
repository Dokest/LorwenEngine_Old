#include "SpriteRenderable.h"

namespace Lorwen { namespace Graphics {

	SpriteRenderable::SpriteRenderable()
	{
	}

	SpriteRenderable::SpriteRenderable(VertexBuffer* vertexBuffer, IndexBuffer* indexBuffer)
		: VBO(vertexBuffer), IBO(indexBuffer)
	{

	}

	SpriteRenderable::~SpriteRenderable()
	{
	}
} }