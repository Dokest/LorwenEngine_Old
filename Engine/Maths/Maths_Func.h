#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

namespace Maths {

	inline float toRadians(float degrees)
	{
		return degrees * (float)M_PI / 180.f;
	}

	inline float clamp(float value, float min, float max)
	{
		return std::max(min, std::min(max, value));
	}

}