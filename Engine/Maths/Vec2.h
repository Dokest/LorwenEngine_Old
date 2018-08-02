#pragma once

#include <iostream>

namespace Lorwen { namespace Maths {

	struct Vec2 
	{
		float x, y;

		Vec2();
		Vec2(const float& x, const float& y);
		
		Vec2& add(const Vec2& other);
		Vec2& substract(const Vec2& other);
		Vec2& multiply(const Vec2& other);
		Vec2& divide(const Vec2& other);

		friend Vec2 operator+(Vec2 left, const Vec2& right);
		friend Vec2 operator-(Vec2 left, const Vec2& right);
		friend Vec2 operator*(Vec2 left, const Vec2& right);
		friend Vec2 operator/(Vec2 left, const Vec2& right);

		friend Vec2 operator*(Vec2 left, const float right);
		friend Vec2 operator/(Vec2 left, const float right);

		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const Vec2& other);

		Vec2& operator/=(const float other);
		Vec2& operator*=(const float other);

		bool operator==(const Vec2& other);
		bool operator!=(const Vec2 & other);

		/* Checks if both vectors are normalize, if they aren't it calculates the DOT PRODUCT with a normalize copy */
		static float DotSecure(Vec2& vector, Vec2& vector2);
		static float Dot(Vec2& vector, Vec2& vector2);
		static Vec2 Normalize(Vec2 vector);

		Vec2& Normalize();

		friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

		float length();
	};







} }
