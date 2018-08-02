#include "SpriteRenderer.h"

#include <typeinfo>

namespace Lorwen { namespace Graphics {

	SpriteRenderer::SpriteRenderer()
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Render()
	{
		float positions[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f
		};

		unsigned int bufferID;
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*)0);
		glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), positions, GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/*
		for (SpriteRenderable& sprite : m_Sprites)
		{
			printf("First!\n");
			//sprite.IBO->Bind();
			sprite.VBO->Bind();
			//glDrawElements(GL_TRIANGLES, (GLsizei)sprite.IBO->GetCount(), GL_UNSIGNED_INT, nullptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			sprite.VBO->Unbind();
			printf("End!\n");
		}
		*/
	}

	void SpriteRenderer::Submit(BaseRenderable* renderable)
	{
		SpriteRenderable* sprite = static_cast<SpriteRenderable*>(renderable);
		if (sprite != nullptr)
			m_Sprites.push_back(*sprite);
		else
			printf("Tried to submit something into SpriteRenderer that was NOT a SpriteRenderable\n");
	}

} }
