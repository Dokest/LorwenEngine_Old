#include "BasicLevel.h"

#include "Maths/Maths.h"
#include <algorithm>

#include "ResourceManager.h"
#include "SpriteRenderable.h"
#include "SpriteRenderer.h"

BasicLevel::BasicLevel()
{

}

BasicLevel::~BasicLevel()
{

}

void BasicLevel::Load()
{
	//ResourceManager::LoadShader("../Engine/Shaders/Basic.vert", "../Engine/Shaders/Basic.frag", nullptr, "Basic");
	ResourceManager::LoadShader("../Engine/Shaders/BatchSprite.vert", "../Engine/Shaders/BatchSprite.frag", nullptr, "Basic2");

	spriteRenderer.Init2();
}

void BasicLevel::Init()
{
	srand(NULL);

	//sprite.GetShader()->Use();
	//sprite.GetShader()->SetMatrix4("pr_matrix", spriteRenderer.GetProjectionMatrix());

	Shader shader = ResourceManager::GetShader("Basic2");
	Vec2 pos;
	Vec2 size(800 / 200, 800 / 200);

	for (int y = 0; y < 200; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			pos = Vec2(x * (size.x + 4.0f), y * (size.x + 4.0f));
			SpriteRenderable sprite = SpriteRenderable(pos, size, &shader);
			sprite.SetTint({ 0.3f, 0.0f, ((float)rand()) / (float)RAND_MAX, 1.0f });
			m_VisibleRenderables.push_back(sprite);
		}
	}

// 	Vec2 size(100.0f, 100.0f);
// 	Shader& shader = ResourceManager::GetShader("Basic2");
// 
// 	SpriteRenderable sprite = SpriteRenderable(Vec2(0.0f, 0.0f), size, &shader);
// 	sprite.SetTint({ 0.3f, 0.0f, 1.0f, 1.0f });
// 
// 	m_VisibleRenderables.push_back(sprite);


 	shader.SetMatrix4("pr_matrix", spriteRenderer.GetProjectionMatrix());

	/* SUBMIT RENDERABLES */
	for (unsigned int i = 0; i < m_VisibleRenderables.size(); i++)
		spriteRenderer.Submit2(m_VisibleRenderables[i]);
}

void BasicLevel::End()
{

}

void BasicLevel::Render()
{

	/* RENDER */
	spriteRenderer.Render2();
	
}
