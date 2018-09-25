#include "LEntityComponent.h"

#include "EEntity.h"

#include "Console/ConsoleLogger.h"

void LEntityComponent::SetAbsoluteLocation(Maths::Vec3 newAbsoluteLocation)
{
	Transform.Position = newAbsoluteLocation;
}

Maths::Vec3 LEntityComponent::GetAbsoluteLocation()
{
	return Transform.Position;
}

void LEntityComponent::SetRelativeLocation(Maths::Vec3 newRelativeLocation)
{
	Transform.Position = (static_cast<EEntity*>(Owner)->Transform.Position) + newRelativeLocation;
}

Maths::Vec3 LEntityComponent::GetRelativeLocation()
{
	return Transform.Position - (static_cast<EEntity*>(Owner)->Transform.Position);
}

void LEntityComponent::OnUpdate(float deltaTime)
{
	Component::OnUpdate(deltaTime);

	//Logger::ConsoleLog("Camera Location = " + std::to_string(GetAbsoluteLocation().y));

	SetAbsoluteLocation(static_cast<EEntity*>(Owner)->Transform.Position + GetRelativeLocation());
}
