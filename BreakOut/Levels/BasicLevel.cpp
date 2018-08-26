#include "BasicLevel.h"

#include "Maths/Maths.h"
#include <algorithm>

#include "Graphics/ResourceManager.h"
#include "Graphics/SpriteRenderable.h"
#include "Graphics/SpriteRenderer.h"

#include "Graphics/SpriteRen.h"

#include "Game/GameObjectRegister.h"
#include "Game/WorldObject.h"

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
	ResourceManager::LoadShader("../Engine/Shaders/BatchSprite.vert", "../Engine/Shaders/BatchSprite.frag", nullptr, "DEFAULT");

	spriteRenderer.Init2();

	GameObjectManager gameManager;

	//SpriteRen* spriteTest = gameManager.Register<SpriteRen>(10);
	SpriteRen* spriteTest = gameManager.RegisterGameObject<SpriteRen>((char)"SpriteTest");
	spriteTest->Construct(Vec2(100.0f, 100.0f), Vec2(100.0f, 100.f));
	spriteRenderer.SubmitSprite(spriteTest);
}

void BasicLevel::Init()
{
	srand(NULL);

	//sprite.GetShader()->Use();
	//sprite.GetShader()->SetMatrix4("pr_matrix", spriteRenderer.GetProjectionMatrix());

	Vec2 pos;
	Vec2 size(800 / 100, 800 / 100);
#if 0
	Shader shader = ResourceManager::GetShader("Basic2");

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

	shader.SetMatrix4("pr_matrix", spriteRenderer.GetProjectionMatrix());

	/* SUBMIT RENDERABLES */
	// 	for (unsigned int i = 0; i < m_VisibleRenderables.size(); i++)
	// 		spriteRenderer.Submit2(m_VisibleRenderables[i]);

#else
 	for (int y = 0; y < 100; y++)
 	{
 		for (int x = 0; x < 100; x++)
 		{
 			pos = Vec2(x * (size.x + 0.0f), y * (size.x + 0.0f));
			SpriteRen* sprite = new SpriteRen();
			sprite->Construct(pos, size);
			sprite->Tint = Vec4(0.4f, 0.0f, ((float)rand()) / (float)RAND_MAX, 1.0f);

			m_Renderables[x + (100 * y)] = sprite;
 		}
 	}
	
	Shader shader = ResourceManager::GetShader("DEFAULT").Use();
	shader.SetMatrix4("pr_matrix", spriteRenderer.GetProjectionMatrix());
 
	//spriteRenderer.SubmitSprite(&m_Renderables, GL_DYNAMIC_DRAW);

 	/* SUBMIT RENDERABLES */
 	//spriteRenderer.SubmitSprite(&m_Renderables);
#endif

// 	Vec2 size(100.0f, 100.0f);
// 	Shader& shader = ResourceManager::GetShader("Basic2");
// 
// 	SpriteRenderable sprite = SpriteRenderable(Vec2(0.0f, 0.0f), size, &shader);
// 	sprite.SetTint({ 0.3f, 0.0f, 1.0f, 1.0f });
// 
// 	m_VisibleRenderables.push_back(sprite);

}

void BasicLevel::End()
{

}

void BasicLevel::Render()
{
	/* RENDER */
	spriteRenderer.Render2();
	
}
