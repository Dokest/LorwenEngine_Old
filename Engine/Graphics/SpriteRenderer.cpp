#include "SpriteRenderer.h"

#include <typeinfo>

#include "VertexArray.h"

namespace Lorwen { namespace Graphics {

	SpriteRenderer::SpriteRenderer()
	{


	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Render()
	{
		m_IBO->Bind();
		m_VAO->Bind();

		m_Sprites[0].UseShader();
		int i = 0;
		for (SpriteRenderable& sprite : m_Sprites)
		{

			sprite.GetShader()->SetMatrix4("mvp", m_ProjectionMatrix *  sprite.GetTransform());
			sprite.GetShader()->SetVector4f("spriteColor", sprite.GetTint());

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
			i++;
		}

	}

	void SpriteRenderer::Submit(BaseRenderable* renderable)
	{
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(4);

		SpriteRenderable* sprite = static_cast<SpriteRenderable*>(renderable);
		if (sprite != nullptr)
		{
			m_Sprites.push_back(*sprite);
		}
		else
			printf("Tried to submit something into SpriteRenderer that was NOT a SpriteRenderable\n");

		printf("Submitted!\n");
	}

	void SpriteRenderer::Init()
	{
		float positions[] = {
			-0.5f, -0.5f,
			 0.5f, -0.5f,
			 0.5f,  0.5f,
			-0.5f,  0.5f
		};

		m_VBO = new VertexBuffer(positions, 4 * 2 * sizeof(float));
		m_VAO = new VertexArray;


		VertexBufferLayout layout;
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);

		unsigned int indices[] =
		{
			0, 1, 2,
			2, 3, 0
		};

		m_IBO = new IndexBuffer(indices, 6);

		m_ProjectionMatrix = Maths::Mat4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
	}

} }
