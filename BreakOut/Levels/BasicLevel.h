#pragma once

#include "Game/BaseLevel.h"

#include "Graphics/BatchSpriteRenderer.h"

#include "Graphics/SpriteRenderer.h"

#include <vector>

class BasicLevel : public BaseLevel
{
public:

private:
	BatchSpriteRenderer spriteRenderer;
	SpriteRenderer renderer;

	std::vector<class LSpriteComponent*> m_SubmissionQueue;

	//std::vector<class SpriteRen*> m_Renderables = std::vector<class SpriteRen*>(100 * 100);

public:
	BasicLevel();
	~BasicLevel();

	virtual void PrepareLevel() override;

	virtual void Load() override;
	
	virtual void Init() override;

	virtual void End() override;

	virtual void Submit(LRenderableComponent* renComp) override;

	virtual void SubmitNextFrame(LRenderableComponent* renComp);
	
	void Render();
};
