#pragma once

#include "BaseRenderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "SpriteRenderable.h" 

#include <vector>

namespace Lorwen { namespace Graphics {

	class SpriteRenderer : public BaseRenderer
	{
	private:
		std::vector<SpriteRenderable> m_Sprites;

	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Render();

		virtual void Submit(BaseRenderable* renderable);
	};
} }

