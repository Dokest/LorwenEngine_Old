#include "Vec2.h"

#include <algorithm>

namespace Lorwen { namespace Maths {

	Vec2::Vec2()
	{
		x = 0.f;
		y = 0.f;
	}

	Vec2::Vec2(const float & x, const float & y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2 & Vec2::add(const Vec2 & other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vec2 & Vec2::substract(const Vec2 & other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vec2 & Vec2::multiply(const Vec2 & other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vec2 & Vec2::divide(const Vec2 & other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	Vec2 & Vec2::operator+=(const Vec2 & other)
	{
		return add(other);
	}

	Vec2 & Vec2::operator-=(const Vec2 & other)
	{
		return substract(other);
	}

	Vec2 & Vec2::operator*=(const Vec2 & other)
	{
		return multiply(other);
	}

	float Vec2::DotSecure(Vec2& vector, Vec2& vector2)
	{
		Vec2 v1, v2;

		if (vector.length() != 1)
			v1 = Normalize(vector);
		else
			v1 = vector;
		if (vector2.length() != 1)
			v2 = Normalize(vector2);
		else
			v2 = vector2;

		return Dot(v1, v2);
	}

	float Vec2::Dot(Vec2& vector, Vec2& vector2)
	{
		return (vector.x * vector2.x) + (vector.y * vector2.y);
	}

	Vec2 Vec2::Normalize(Vec2 vector)
	{
		return Vec2(vector.Normalize());
	}

	Vec2& Vec2::Normalize()
	{
		float vectorLength = length();
		x /= vectorLength;
		y /= vectorLength;

		return *this;
	}

	float Vec2::length()
	{
		return std::sqrt((x * x) + (y * y));
	}

	Vec2& Vec2::operator/=(const float other)
	{
		x /= other;
		y /= other;

		return *this;
	}

	Vec2& Vec2::operator*=(const float other)
	{
		x *= other;
		y *= other;

		return *this;
	}

	Vec2 & Vec2::operator/=(const Vec2 & other)
	{
		return divide(other);
	}

	bool Vec2::operator==(const Vec2 & other)
	{
		return x == other.x && y == other.y;
	}

	bool Vec2::operator!=(const Vec2 & other)
	{
		return !(*this == other);
	}

	Vec2 operator+(Vec2 left, const Vec2 & right)
	{
		return left.add(right);
	}

	Vec2 operator-(Vec2 left, const Vec2 & right)
	{
		return left.substract(right);
	}

	Vec2 operator*(Vec2 left, const Vec2 & right)
	{
		return left.multiply(right);
	}

	Vec2 operator/(Vec2 left, const Vec2 & right)
	{
		return left.divide(right);
	}

	Vec2 operator*(Vec2 left, const float right)
	{
		return Vec2(left.x * right, left.y * right);
	}

	Vec2 operator/(Vec2 left, const float right)
	{
		return Vec2(left.x / right, left.y / right);
	}

	std::ostream & Maths::operator<<(std::ostream & stream, const Vec2 & vector)
	{
		return stream << "vec2: (" << vector.x << ", " << vector.y << ")";
	}




	//END
} }
