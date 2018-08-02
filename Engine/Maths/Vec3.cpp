#include "Vec3.h"


namespace Lorwen { namespace Maths {

	Vec3::Vec3()
	{
		x = 0.f;
		y = 0.f;
		z = 0.f;
	}

	Vec3::Vec3(const float & x, const float & y,const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3::Vec3(const float& xyz)
		: x(xyz), y(xyz), z(xyz)
	{

	}

	Vec3 & Vec3::add(const Vec3 & other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vec3 & Vec3::substract(const Vec3 & other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vec3 & Vec3::multiply(const Vec3 & other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	Vec3 & Vec3::divide(const Vec3 & other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	Vec3 & Vec3::operator+=(const Vec3 & other)
	{
		return add(other);
	}

	Vec3 & Vec3::operator-=(const Vec3 & other)
	{
		return substract(other);
	}

	Vec3 & Vec3::operator*=(const Vec3 & other)
	{
		return multiply(other);
	}

	Vec3 & Vec3::operator/=(const Vec3 & other)
	{
		return divide(other);
	}

	bool Vec3::operator==(const Vec3 & other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vec3::operator!=(const Vec3 & other)
	{
		return !(*this == other);
	}

	Vec3 operator+(Vec3 left, const Vec3 & right)
	{
		return left.add(right);
	}

	Vec3 operator-(Vec3 left, const Vec3 & right)
	{
		return left.substract(right);
	}

	Vec3 operator*(Vec3 left, const Vec3 & right)
	{
		return left.multiply(right);
	}

	Vec3 operator/(Vec3 left, const Vec3 & right)
	{
		return left.divide(right);
	}

	std::ostream & Maths::operator<<(std::ostream & stream, const Vec3 & vector)
	{
		return stream << "Vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	}




	//END
} }
