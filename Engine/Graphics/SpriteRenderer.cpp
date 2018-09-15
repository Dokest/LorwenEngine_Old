#include "SpriteRenderer.h"

#include <typeinfo>
#include <array>

#include "VertexArray.h"

#include "LSpriteComponent.h"

#include "SpriteMaterialManager.h"


SpriteRenderer::SpriteRenderer()
{


}

void SpriteRenderer::Render()
{

	for (SInstanciatedSprite& instances : m_Sprites)
	{
		//ShowOpenGLErrors();
		instances.Material->pShader->Use();
		instances.Material->pShader->SetMatrix4("pr_matrix", m_ProjectionMatrix);
		//ShowOpenGLErrors();
		std::array<float, 500> buffer;
		unsigned int i = 0;


		glActiveTexture(GL_TEXTURE0);
		instances.Material->Texture->Bind();


		for (LSpriteComponent* sprite : instances.Renderables)
		{
			Vec2 loc = sprite->GetLocation();
			Vec2 size = sprite->GetSize();
			Vec4 tint = sprite->GetTint();

			buffer[i] = loc.x - (size.x / 2);
			buffer[i + 1] = loc.y + (size.y / 2);
			buffer[i + 2] = tint.x;
			buffer[i + 3] = tint.y;
			buffer[i + 4] = tint.z;
			buffer[i + 5] = tint.w;
			buffer[i + 6] = 0.0f;
			buffer[i + 7] = 0.0f;

			i += 8;

			buffer[i] = loc.x + (size.x / 2);
			buffer[i + 1] = loc.y + (size.y / 2);
			buffer[i + 2] = tint.x;
			buffer[i + 3] = tint.y;
			buffer[i + 4] = tint.z;
			buffer[i + 5] = tint.w;
			buffer[i + 6] =  1.0f;
			buffer[i + 7] =  0.0f;

			i += 8;

			buffer[i] = loc.x + (size.x / 2);
			buffer[i + 1] = loc.y - (size.y / 2);
			buffer[i + 2] = tint.x;
			buffer[i + 3] = tint.y;
			buffer[i + 4] = tint.z;
			buffer[i + 5] = tint.w;
			buffer[i + 6] = 1.0f;
			buffer[i + 7] = 1.0f;

			i += 8;

			buffer[i] = loc.x - (size.x / 2);
			buffer[i + 1] = loc.y - (size.y / 2);
			buffer[i + 2] = tint.x;
			buffer[i + 3] = tint.y;
			buffer[i + 4] = tint.z;
			buffer[i + 5] = tint.w;
			buffer[i + 6] = 0.0f;
			buffer[i + 7] = 1.0f;

			i += 8;
		}

		instances.Material->pVBO->BufferData(sizeof(buffer), &buffer[0], GL_STATIC_DRAW);

		instances.Material->pIBO->Bind();
		instances.Material->pVAO->Bind();

		glDrawElements(GL_TRIANGLES, i / 4, GL_UNSIGNED_INT, NULL);
	}
}


void SpriteRenderer::Submit(unsigned int hspriteName, LSpriteComponent* sprite)
{
	for (SInstanciatedSprite& instancedSprite : m_Sprites)
	{
		if (instancedSprite.hSpriteName == hspriteName)
		{
			instancedSprite.Renderables.push_back(sprite);

			return; // When the new Sprite has been added, function ended.
		}
	}

	// If the sprite hasn't been added yet, we need to create a new instance for it
	SInstanciatedSprite iSprite;
	iSprite.hSpriteName = hspriteName;
	iSprite.Material = &SpriteMaterialManager::GetMaterial(sprite->GetMaterialID());
	iSprite.Renderables.push_back(sprite);

	VertexBufferLayout* layout = new VertexBufferLayout();
	layout->Push<float>(2);
	layout->Push<float>(4, true);
	layout->Push<float>(2);

	iSprite.Material->pVAO->AddBuffer(*iSprite.Material->pVBO, *layout);

	m_Sprites.push_back(iSprite);
}

void SpriteRenderer::Submit(const char* spriteName, class LSpriteComponent* sprite)
{
	unsigned int hspriteName = m_Hasher(spriteName);

	Submit(hspriteName, sprite);
}

void SpriteRenderer::Init(const float width, const float height)
{
	m_ProjectionMatrix = Maths::Mat4::Orthographic(0.0f, width, 0.0f, height, -1.0f, 1.0f);
}

