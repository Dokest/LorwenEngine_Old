#pragma once

#include "Maths_Func.h"
#include "Vec3.h"
#include "Vec4.h"

namespace Lorwen { namespace Maths {

	struct Mat4
	{
		union
		{
			float Elements[4 * 4];
			Vec4 Columns[4];
		};


		Mat4();
		Mat4(float diagonal);

		static Mat4 Identity();

		Mat4& Multiply(const Mat4& other);
		friend Mat4 operator*(Mat4 left, const Mat4& right);
		Mat4& operator*=(const Mat4& other);

		/* Vec3 */
		Vec3 Multiply(const Vec3& other) const;
		friend Vec3 operator*(const Mat4& left, const Vec3& right);

		/* Vec4 */
		Vec4 Multiply(const Vec4& other) const;
		friend Vec4 operator*(const Mat4& left, const Vec4& right);

		Mat4& Invert();

		static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Mat4 Perspective(float fov, float aspectRatio, float near, float far);

		static Mat4 Translation(const Vec3& translation);
		static Mat4 Rotation(float angle, const Vec3& axis);
		static Mat4 Scale(const Vec3& scale);

		void ShowMat4();

	};

} }