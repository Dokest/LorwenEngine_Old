#pragma once

#include "Game/EEntity.h"

#include "Shader.h"
#include "ResourceManager.h"


enum class ERenderableType : unsigned char
{
	Sprite = 0,
	StaticSprite = 1,
	StaticMesh = 10,
	DynamicMesh = 11
};

class Renderable : public EEntity
{
protected:
	ERenderableType m_RenderableType = ERenderableType::Sprite;

	Shader* m_Shader = &ResourceManager::GetShader("DEFAULT");
public:
	bool bIsVisible = true;

public:
	Renderable();
	Renderable(STransform transform, ERenderableType renderableType);
	~Renderable();

public:
};


