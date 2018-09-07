#pragma once

#include "LRenderableComponent.h"

#include "Maths/Maths.h"

#include "Shader.h"

#include "IndexBuffer.h"
#include "VertexBuffer.h"

#include <vector>

class LSpriteComponent : public LRenderableComponent
{
private:
	Maths::Vec2 SpritePosition;
	Maths::Vec2 SpriteSize = Maths::Vec2(100.f, 100.f);
	Shader* SpriteShader;
	Maths::Vec4 SpriteTint = Maths::Vec4(1.0f, 1.0f, 1.0f, 1.0f);

	Maths::Mat4 Transform;

	/* Material */
	unsigned int m_MaterialID = 0;

public:
	LSpriteComponent();
	LSpriteComponent(Maths::Vec2 position, Maths::Vec2 size, Shader* shader);
	~LSpriteComponent();

public:

	//void SetLocation(Maths::Vec2 newLocation);
	void SetLocation(Maths::Vec2 newLocation) { SpritePosition = newLocation; }
	inline const Maths::Vec2 GetLocation() const { return SpritePosition; }

	//void SetSize(Maths::Vec2 newScale);
	inline void SetSize(Maths::Vec2 newSize) { SpriteSize = newSize; }
	inline const Maths::Vec2 GetSize() const { return SpriteSize; }

	void SetTint(Maths::Vec4 newColor);
	inline const Maths::Vec4 GetTint() const { return SpriteTint; }

	inline void UseShader() const { SpriteShader->Use(); }
	inline Shader* GetShader() const { return SpriteShader; }

	inline const Mat4 GetTransform() const { return Transform; }

	/**
	 *	Material
	 */
	inline void SetMaterialID(unsigned int materialID) { m_MaterialID = materialID; }
	inline unsigned int GetMaterialID() { return m_MaterialID; }

};


