#include "SpriteRenderable.h"

namespace Lorwen { namespace Graphics {

	SpriteRenderable::SpriteRenderable()
	{
	}

	SpriteRenderable::SpriteRenderable(Maths::Vec2 position, Maths::Vec2 size, Shader* shader)
		: SpritePosition(position), SpriteSize(size), SpriteShader(shader), Transform(Maths::Mat4::Identity())
	{
		SpriteShader->Use();
		Transform *= Maths::Mat4::Translation(Vec3(position.x, position.y, 0.0f));
		Transform *= Maths::Mat4::Scale(Vec3(size.x, size.y, 1.0f));
		SpriteShader->SetMatrix4("model", Transform);
	}


	SpriteRenderable::~SpriteRenderable()
	{
	}

	void SpriteRenderable::SetLocation(Maths::Vec2 newLocation)
	{
		SpriteShader->Use();

		Transform *= Maths::Mat4::Translation(Vec3(newLocation.x, newLocation.y, 0.0f));
		SpriteShader->SetMatrix4("model", Transform);
	}

	void SpriteRenderable::SetSize(Maths::Vec2 newScale)
	{
		SpriteShader->Use();

		Transform *= Maths::Mat4::Scale(Vec3(newScale.x, newScale.y, 1.0f));
		SpriteShader->SetMatrix4("model", Transform);
	}

	void SpriteRenderable::SetTint(Maths::Vec4 newColor)
	{
		SpriteTint = newColor;
	}

} }