#pragma once

#include "BaseLevel.h"

#include "BatchSpriteRenderer.h"

using namespace Lorwen;
using namespace Graphics;

class BasicLevel : public BaseLevel
{
private:
	BatchSpriteRenderer spriteRenderer;

	std::vector<SpriteRenderable> m_VisibleRenderables;

public:
	BasicLevel();
	~BasicLevel();

	virtual void Load();
	
	virtual void Init();

	virtual void End();
	
	void Render();
};
