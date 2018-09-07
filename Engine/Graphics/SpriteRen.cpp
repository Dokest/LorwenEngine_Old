#include "SpriteRen.h"

#include "Graphics/BatchSpriteRenderer.h"

BatchSpriteRenderer* SpriteRen::m_Renderer = nullptr;

SpriteRen::SpriteRen()
{
	m_RenderableType = ERenderableType::StaticSprite;
}

SpriteRen::~SpriteRen()
{
}

void SpriteRen::Preparation()
{
	m_Renderer->SubmitSprite(this);
}

void SpriteRen::Construct(Vec2 pos, Vec2 size)
{
	m_RenderableType = ERenderableType::StaticSprite;
	Transform.Position = Vec3(pos.x, pos.y, 0.0f);
	Transform.Size = Vec3(size.x, size.y, 0.0f);
}
