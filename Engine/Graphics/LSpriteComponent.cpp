#include "LSpriteComponent.h"

#include "ResourceManager.h"

#include "SpriteMaterialManager.h"

LSpriteComponent::LSpriteComponent()
	: SpritePosition(Vec2()), SpriteSize(Vec2()), SpriteShader(&ResourceManager::GetShader("DEFAULT")), Transform(Maths::Mat4::Identity())
	, m_MaterialID(SpriteMaterialManager::GetMaterial("DEFAULT").ID)
{
	SpriteShader->Use();
	Transform *= Maths::Mat4::Translation(Vec3(0.0f, 0.0f, 0.0f));
	Transform *= Maths::Mat4::Scale(Vec3(20.0f, 20.0f, 1.0f));
	SpriteShader->SetMatrix4("model", Transform);

}

LSpriteComponent::LSpriteComponent(Maths::Vec2 position, Maths::Vec2 size, Shader* shader)
	: SpritePosition(position), SpriteSize(size), SpriteShader(shader), Transform(Maths::Mat4::Identity())
{
	SpriteShader->Use();
	Transform *= Maths::Mat4::Translation(Vec3(position.x, position.y, 0.0f));
	Transform *= Maths::Mat4::Scale(Vec3(size.x, size.y, 1.0f));
	SpriteShader->SetMatrix4("model", Transform);
}


LSpriteComponent::~LSpriteComponent()
{
}

// void LSpriteComponent::SetLocation(Maths::Vec2 newLocation)
// {
// 	SpriteShader->Use();
// 
// 	Transform *= Maths::Mat4::Translation(Vec3(newLocation.x, newLocation.y, 0.0f));
// 	SpriteShader->SetMatrix4("model", Transform);
// }

// void LSpriteComponent::SetSize(Maths::Vec2 newScale)
// {
// 	SpriteShader->Use();
// 
// 	Transform *= Maths::Mat4::Scale(Vec3(newScale.x, newScale.y, 1.0f));
// 	SpriteShader->SetMatrix4("model", Transform);
// }

void LSpriteComponent::SetTint(Maths::Vec4 newColor)
{
	SpriteTint = newColor;
}
