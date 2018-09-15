#pragma once

#include "BaseRenderer.h"

#include "LRenderableComponent.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "SpriteMaterialManager.h"

#include <vector>


struct SInstanciatedSprite
{
	unsigned int hSpriteName;
	SpriteMaterial* Material;
	std::vector<class LSpriteComponent*> Renderables;
};


class SpriteRenderer : public BaseRenderer
{
private:
	std::vector<SInstanciatedSprite> m_Sprites;
	std::hash<std::string> m_Hasher;

public:
	SpriteRenderer();

public:
	virtual void Render();

	void Submit(unsigned int hspriteName, class LSpriteComponent* sprite);
	void Submit(const char* spriteName, class LSpriteComponent* sprite);

	void Init(const float width, const float height);
};

