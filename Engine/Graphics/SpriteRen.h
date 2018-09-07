#pragma once

#include "Renderable.h"

class SpriteRen : public Renderable
{
public:
	Vec4 Tint = Vec4(0.8f, 0.0f, 0.6f, 1.0f);
	static class BatchSpriteRenderer* m_Renderer;

	class Shader* m_Shader = &ResourceManager::GetShader("DEFAULT");

public:
	SpriteRen();
	~SpriteRen();

private:
	virtual void Preparation();

public:
	void Construct(Vec2 pos, Vec2 size);

	inline const Shader* GetShader() const { return m_Shader; }


};

