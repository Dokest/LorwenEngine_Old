#include "BatchSpriteRenderer.h"

#include <GL/glew.h>

#include "DebugOpenGL.h"

#include "ResourceManager.h"
#include "SpriteRenderable.h"
#include "VertexBufferLayout.h"

#include "SpriteRen.h"

namespace Lorwen { namespace Graphics {


	BatchSpriteRenderer::BatchSpriteRenderer()
	{
		m_ProjectionMatrix = Maths::Mat4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, 1.0f, -1.0f);
		m_IndexCount = 0;
	}

	BatchSpriteRenderer::~BatchSpriteRenderer()
	{
		delete m_IBO;
		delete m_VAO;
		delete m_VBO;
	}

	void BatchSpriteRenderer::Init()
	{
		/* PROJECTION MATRIX */
		m_ProjectionMatrix = Maths::Mat4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, 1.0f, -1.0f);

		glGenVertexArrays(1, &VAO);
		
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (const void*)0);
		
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(float) * 6, (const void*) (2 * sizeof(float)));
		
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_STATIC_DRAW);

		unsigned int* Indices = new unsigned int[RENDERER_INDICES_SIZE];

		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			Indices[  i  ] = offset + 0;
			Indices[i + 1] = offset + 1;
			Indices[i + 2] = offset + 2;

			Indices[i + 3] = offset + 2;
			Indices[i + 4] = offset + 3;
			Indices[i + 5] = offset + 0;

			offset += 4;
		}

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, RENDERER_INDICES_SIZE, Indices, GL_STATIC_DRAW);

		glBindVertexArray(0);
		delete Indices;
	}

	void BatchSpriteRenderer::Init2()
	{
		/* PROJECTION MATRIX */
		m_ProjectionMatrix = Maths::Mat4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, 1.0f, -1.0f);

		m_VAO = new VertexArray();

		m_VBO = new VertexBuffer();
		ShowOpenGLErrors();
		m_Layout = new VertexBufferLayout();
		m_Layout->Push<float>(2);
		m_Layout->Push<float>(4, GL_TRUE);
		ShowOpenGLErrors();
		m_VAO->AddBuffer(*m_VBO, *m_Layout);
		ShowOpenGLErrors();

		m_VBO->BufferData(RENDERER_BUFFER_SIZE, NULL, GL_STATIC_DRAW);

		unsigned int* Indices = new unsigned int[RENDERER_INDICES_SIZE];

		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			Indices[i] = offset + 0;
			Indices[i + 1] = offset + 1;
			Indices[i + 2] = offset + 2;

			Indices[i + 3] = offset + 2;
			Indices[i + 4] = offset + 3;
			Indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IBO = new IndexBuffer(Indices, RENDERER_INDICES_SIZE, GL_STATIC_DRAW);

		m_VAO->Unbind();

		delete Indices;
	}

	void BatchSpriteRenderer::Submit(BaseRenderable* renderable)
	{
		SpriteRenderable* sprite = static_cast<SpriteRenderable*>(renderable);
		if (sprite == nullptr)
		{
			printf("Sprite renderer received an non SpriteRenderable object at line %d", __LINE__);
			return;
		}

		//m_Sprites.push_back(*sprite);

		const Vec2& Position = sprite->GetLocation();
		const Vec4& Color = sprite->GetTint();
		const Vec2& Size = sprite->GetSize();

		//std::cout << "Position: " << Position << " Size: " << Size << " Color: " << Color << std::endl;
		
		float buffer[] =
		{
			/* VERTEX */								/* COLOR */
			Position.x,  Position.y + Size.y,			Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y, Color.x,	Color.y, Color.z, Color.w,
			Position.x, Position.y, Color.x, Color.y,	Color.z, Color.w
		};

		m_IndexCount += 6;
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, ((m_IndexCount / 6) - 1) * sizeof(buffer), sizeof(buffer), buffer);


// 		m_Buffer->Vertex = Vec2(Position.x, Position.y + Size.y);
// 		m_Buffer->Color = Color;
// 		m_Buffer++;
// 
// 		m_Buffer->Vertex = Vec2(Position.x + Size.x, Position.y + Size.y);
// 		m_Buffer->Color = Color;
// 		m_Buffer++;
// 
// 		m_Buffer->Vertex = Vec2(Position.x + Size.x, Position.y);
// 		m_Buffer->Color = Color;
// 		m_Buffer++;
// 
// 		m_Buffer->Vertex = Vec2(Position.x, Position.y);
// 		m_Buffer->Color = Color;
// 		m_Buffer++;
// 
// 		m_IndexCount += 6;

	}

	void BatchSpriteRenderer::Submit(SpriteRenderable& sprite)
	{
		const Vec2& Position = sprite.GetLocation();
		const Vec4& Color = sprite.GetTint();
		const Vec2& Size = sprite.GetSize();

		float buffer[] =
		{
			/* VERTEX */								/* COLOR */
			Position.x,  Position.y + Size.y,			Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y, Color.x,	Color.y, Color.z, Color.w,
			Position.x, Position.y, Color.x, Color.y,	Color.z, Color.w
		};

		m_IndexCount += 6;

		//glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferSubData(GL_ARRAY_BUFFER, ((m_IndexCount / 6) - 1) * sizeof(buffer), sizeof(buffer), buffer);
	}

	void BatchSpriteRenderer::SubmitSprite(SpriteRen* sprite)
	{
		const Vec2& Position = Vec2(sprite->Transform.Position.x, sprite->Transform.Position.y);
		const Vec4& Color = sprite->Tint;
		const Vec2& Size = Vec2(sprite->Transform.Size.x, sprite->Transform.Size.y);

		float buffer[] =
		{
			/* VERTEX */								/* COLOR */
			Position.x,			 Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y,			Color.x, Color.y, Color.z, Color.w,
			Position.x,			 Position.y,			Color.x, Color.y, Color.z, Color.w
		};

		m_IndexCount += 6;

		m_VBO->Bind();
		glBufferSubData(GL_ARRAY_BUFFER, ((m_IndexCount / 6) - 1) * sizeof(buffer), sizeof(buffer), buffer);
	}

	void BatchSpriteRenderer::SubmitSprite(std::vector<SpriteRen*>* sprites, GLenum drawType)
	{
		std::vector<float> buffers;

		SpriteRen* sprite;

		//printf("Mass submit -> Nº %d, %d\n", sprites->size(), buffers.size());

		for (unsigned int i = 0; i < sprites->size(); i++)
		{
			sprite = (*sprites)[i];

			/* If Sprite is not VISIBLE it should be skipped! */
			if (!sprite->bIsVisible)
				continue;

			const Vec2& Position = Vec2(sprite->Transform.Position.x, sprite->Transform.Position.y);
			const Vec4& Color = sprite->Tint;
			const Vec2& Size = Vec2(sprite->Transform.Size.x, sprite->Transform.Size.y);

			buffers.push_back(Position.x);
			buffers.push_back(Position.y + Size.y);
			buffers.push_back(Color.x);
			buffers.push_back(Color.y);
			buffers.push_back(Color.z);
			buffers.push_back(Color.w);

			buffers.push_back(Position.x + Size.x);
			buffers.push_back(Position.y + Size.y);
			buffers.push_back(Color.x);
			buffers.push_back(Color.y);
			buffers.push_back(Color.z);
			buffers.push_back(Color.w);

			buffers.push_back(Position.x + Size.x);
			buffers.push_back(Position.y);
			buffers.push_back(Color.x);
			buffers.push_back(Color.y);
			buffers.push_back(Color.z);
			buffers.push_back(Color.w);

			buffers.push_back(Position.x);
			buffers.push_back(Position.y);
			buffers.push_back(Color.x);
			buffers.push_back(Color.y);
			buffers.push_back(Color.z);
			buffers.push_back(Color.w);
		}
		
			m_IndexCount += 6 * sprites->size();
			m_VBO->Bind();
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffers.size(), &buffers[0], drawType);

			buffers.clear();
	}

	void BatchSpriteRenderer::Submit2(SpriteRenderable& sprite)
	{
		const Vec2& Position = sprite.GetLocation();
		const Vec4& Color = sprite.GetTint();
		const Vec2& Size = sprite.GetSize();

		float buffer[] =
		{
			/* VERTEX */								/* COLOR */
			Position.x,			 Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y + Size.y,	Color.x, Color.y, Color.z, Color.w,
			Position.x + Size.x, Position.y,			Color.x, Color.y, Color.z, Color.w,
			Position.x,			 Position.y,			Color.x, Color.y, Color.z, Color.w
		};

		m_IndexCount += 6;

		m_VBO->Bind();
		glBufferSubData(GL_ARRAY_BUFFER, ((m_IndexCount / 6) - 1) * sizeof(buffer), sizeof(buffer), buffer);
	}

	void BatchSpriteRenderer::Render()
	{
#if 0
		float vertex[] = {
			 /* VERTEX */		/* COLOR */
			-0.5f,  0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f,			0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f,			0.0f, 0.0f, 1.0f, 1.0f
		};

		glGenVertexArrays(1, &VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (const void*)0);

 		glEnableVertexAttribArray(1);
 		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(float) * 6, (const void*) (2 * sizeof(float)));

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

		unsigned int ind[] = 
		{
			0, 1, 2,
			2, 3, 0
		};

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), ind, GL_STATIC_DRAW);


		
#else
		glBindVertexArray(VAO);
		//m_IBO->Bind();

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

// 		ShowOpenGLErrors();
// 		m_Sprites[0].GetShader()->Use();
// 		m_Sprites[0].GetShader()->SetMatrix4("pr_matrix", m_ProjectionMatrix);
#endif
		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);
		//printf("SPRITES DRAWN = %d\n", (m_IndexCount / 6));
 		ShowOpenGLErrors();
// 		m_IBO->Unbind();
// 		glBindVertexArray(0);

		//m_IndexCount = 0;
	}

	void BatchSpriteRenderer::Render2()
	{
		m_VAO->Bind();

		m_IBO->Bind();

		ShowOpenGLErrors();
		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);
		ShowOpenGLErrors();
	}

	void BatchSpriteRenderer::Begin()
	{
		//glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBindVertexArray(VAO);

		//m_Buffer = (BatchSprite*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchSpriteRenderer::End()
	{
		//glUnmapBuffer(GL_ARRAY_BUFFER);
		//glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_STATIC_DRAW);

		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} }