#pragma once

#include "BaseRenderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include "SpriteRenderable.h" 

#include <vector>

namespace Lorwen { namespace Graphics {

	class SpriteRenderer : public BaseRenderer
	{
	private:
		std::vector<SpriteRenderable> m_Sprites;

		IndexBuffer* m_IBO;
		VertexArray* m_VAO;
		VertexBuffer* m_VBO;

	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Render();

		virtual void Submit(BaseRenderable* renderable);

		void Init();
	};
} }

