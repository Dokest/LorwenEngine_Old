#pragma once

#include "Game/BaseLevel.h"

#include "Graphics/BatchSpriteRenderer.h"

using namespace Lorwen;
using namespace Graphics;

class BasicLevel : public BaseLevel
{
private:
	BatchSpriteRenderer spriteRenderer;

	std::vector<SpriteRenderable> m_VisibleRenderables;
	std::vector<class SpriteRen*> m_Renderables = std::vector<class SpriteRen*>(100 * 100);

public:
	BasicLevel();
	~BasicLevel();

	virtual void Load();
	
	virtual void Init();

	virtual void End();
	
	void Render();
};
