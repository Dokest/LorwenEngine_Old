#pragma once

#include "Component.h"

#include "STransform.h"

class LEntityComponent : public Component
{
public:
	STransform Transform;

public:
	void SetAbsoluteLocation(Maths::Vec3 newAbsoluteLocation);
	Maths::Vec3 GetAbsoluteLocation();

	void SetRelativeLocation(Maths::Vec3 newRelativeLocation);
	Maths::Vec3 GetRelativeLocation();

private:
	virtual void OnUpdate(float deltaTime);

};

