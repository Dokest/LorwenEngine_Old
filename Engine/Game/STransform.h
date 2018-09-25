#pragma once

#include "Maths/Maths.h"

using namespace Maths;

struct STransform
{
	Vec3 Position;
	Vec3 Size;
	Vec3 Rotation;

	STransform() {}
	STransform(Vec3 position, Vec3 size, Vec3 rotation, float rotationAngle)
		: Position(position), Size(size), Rotation(rotation) { }

};
