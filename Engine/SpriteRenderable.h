#pragma once

#include "BaseRenderable.h"

#include "Maths/Maths.h"

#include "Shader.h"

#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace Lorwen { namespace Graphics {

	class SpriteRenderable : public BaseRenderable
	{
	private:
		Maths::Vec2 SpritePosition;
		Maths::Vec2 SpriteSize;
		Shader* SpriteShader;
		Maths::Vec4 SpriteTint;

		Maths::Mat4 Transform;

	public:
		SpriteRenderable();
		SpriteRenderable(Maths::Vec2 position, Maths::Vec2 size, Shader* shader);
		~SpriteRenderable();


	public:

		void SetLocation(Maths::Vec2 newLocation);
		inline const Maths::Vec2 GetLocation() const { return SpritePosition; }

		void SetSize(Maths::Vec2 newScale);
		inline const Maths::Vec2 GetSize() const { return SpriteSize; }

		void SetTint(Maths::Vec4 newColor);
		inline const Maths::Vec4 GetTint() const { return SpriteTint; }

		inline void UseShader() const { SpriteShader->Use(); }
		inline Shader* GetShader() const { return SpriteShader; }

		inline const Mat4 GetTransform() const { return Transform; }
	};
} }


