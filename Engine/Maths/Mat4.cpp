#include "Mat4.h"

namespace Lorwen { namespace Maths {

	Mat4::Mat4()
	{
		for (int i = 0; i < 4 * 4; i++)
			Elements[i] = 0.0f;
	}

	Mat4::Mat4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
			Elements[i] = 0;

		Elements[0 + 0 * 4] = diagonal;
		Elements[1 + 1 * 4] = diagonal;
		Elements[2 + 2 * 4] = diagonal;
		Elements[3 + 3 * 4] = diagonal;
	}

	Mat4 Mat4::Identity()
	{
		return Mat4(1.0f);
	}

	Mat4& Mat4::Multiply(const Mat4& other)
	{
		float Data[16];
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += Elements[x + e * 4] * other.Elements[e + y * 4];
				}

				Data[x + y * 4] = sum;
			}
		}
		memcpy(Elements, Data, 4 * 4 * sizeof(float));

		return *this;
	}

	Mat4 operator*(Mat4 left, const Mat4& right)
	{
		return left.Multiply(right);
	}

	Mat4& Mat4::operator*=(const Mat4& other)
	{
		return Multiply(other);
	}

	Lorwen::Maths::Mat4& Mat4::Invert()
	{
		float temp[16];

		temp[0] = 
			Elements[5]		* Elements[10]	* Elements[15] -
			Elements[5]		* Elements[11]	* Elements[14] -
			Elements[9]		* Elements[6]	* Elements[15] +
			Elements[9]		* Elements[7]	* Elements[14] +
			Elements[13]	* Elements[6]	* Elements[11] -
			Elements[13]	* Elements[7]	* Elements[10];

		temp[4] = 
			-Elements[4]	* Elements[10]	* Elements[15] +
			Elements[4]		* Elements[11]	* Elements[14] +
			Elements[8]		* Elements[6]	* Elements[15] -
			Elements[8]		* Elements[7]	* Elements[14] -
			Elements[12]	* Elements[6]	* Elements[11] +
			Elements[12]	* Elements[7]	* Elements[10];

		temp[8] = 
			Elements[4]		* Elements[9]	* Elements[15] -
			Elements[4]		* Elements[11]	* Elements[13] -
			Elements[8]		* Elements[5]	* Elements[15] +
			Elements[8]		* Elements[7]	* Elements[13] +
			Elements[12]	* Elements[5]	* Elements[11] -
			Elements[12]	* Elements[7]	* Elements[9];

		temp[12] = 
			-Elements[4]	* Elements[9]	* Elements[14] +
			Elements[4]		* Elements[10]	* Elements[13] +
			Elements[8]		* Elements[5]	* Elements[14] -
			Elements[8]		* Elements[6]	* Elements[13] -
			Elements[12]	* Elements[5]	* Elements[10] +
			Elements[12]	* Elements[6]	* Elements[9];

		temp[1] = 
			-Elements[1]	* Elements[10]	* Elements[15] +
			Elements[1]		* Elements[11]	* Elements[14] +
			Elements[9]		* Elements[2]	* Elements[15] -
			Elements[9]		* Elements[3]	* Elements[14] -
			Elements[13]	* Elements[2]	* Elements[11] +
			Elements[13]	* Elements[3]	* Elements[10];

		temp[5] = 
			Elements[0]		* Elements[10]	* Elements[15] -
			Elements[0]		* Elements[11]	* Elements[14] -
			Elements[8]		* Elements[2]	* Elements[15] +
			Elements[8]		* Elements[3]	* Elements[14] +
			Elements[12]	* Elements[2]	* Elements[11] -
			Elements[12]	* Elements[3]	* Elements[10];

		temp[9] = 
			-Elements[0]	* Elements[9]	* Elements[15] +
			Elements[0]		* Elements[11]	* Elements[13] +
			Elements[8]		* Elements[1]	* Elements[15] -
			Elements[8]		* Elements[3]	* Elements[13] -
			Elements[12]	* Elements[1]	* Elements[11] +
			Elements[12]	* Elements[3]	* Elements[9];

		temp[13] = 
			Elements[0]		* Elements[9]	* Elements[14] -
			Elements[0]		* Elements[10]	* Elements[13] -
			Elements[8]		* Elements[1]	* Elements[14] +
			Elements[8]		* Elements[2]	* Elements[13] +
			Elements[12]	* Elements[1]	* Elements[10] -
			Elements[12]	* Elements[2]	* Elements[9];

		temp[2] = 
			Elements[1]		* Elements[6]	* Elements[15] -
			Elements[1]		* Elements[7]	* Elements[14] -
			Elements[5]		* Elements[2]	* Elements[15] +
			Elements[5]		* Elements[3]	* Elements[14] +
			Elements[13]	* Elements[2]	* Elements[7] -
			Elements[13]	* Elements[3]	* Elements[6];

		temp[6] = 
			-Elements[0]	* Elements[6]	* Elements[15] +
			Elements[0]		* Elements[7]	* Elements[14] +
			Elements[4]		* Elements[2]	* Elements[15] -
			Elements[4]		* Elements[3]	* Elements[14] -
			Elements[12]	* Elements[2]	* Elements[7] +
			Elements[12]	* Elements[3]	* Elements[6];

		temp[10] = 
			Elements[0]		* Elements[5]	* Elements[15] -
			Elements[0]		* Elements[7]	* Elements[13] -
			Elements[4]		* Elements[1]	* Elements[15] +
			Elements[4]		* Elements[3]	* Elements[13] +
			Elements[12]	* Elements[1]	* Elements[7] -
			Elements[12]	* Elements[3]	* Elements[5];

		temp[14] = 
			-Elements[0]	* Elements[5]	* Elements[14] +
			Elements[0]		* Elements[6]	* Elements[13] +
			Elements[4]		* Elements[1]	* Elements[14] -
			Elements[4]		* Elements[2]	* Elements[13] -
			Elements[12]	* Elements[1]	* Elements[6] +
			Elements[12]	* Elements[2]	* Elements[5];

		temp[3] = -Elements[1] * Elements[6] * Elements[11] +
			Elements[1] * Elements[7] * Elements[10] +
			Elements[5] * Elements[2] * Elements[11] -
			Elements[5] * Elements[3] * Elements[10] -
			Elements[9] * Elements[2] * Elements[7] +
			Elements[9] * Elements[3] * Elements[6];

		temp[7] = Elements[0] * Elements[6] * Elements[11] -
			Elements[0] * Elements[7] * Elements[10] -
			Elements[4] * Elements[2] * Elements[11] +
			Elements[4] * Elements[3] * Elements[10] +
			Elements[8] * Elements[2] * Elements[7] -
			Elements[8] * Elements[3] * Elements[6];

		temp[11] = -Elements[0] * Elements[5] * Elements[11] +
			Elements[0] * Elements[7] * Elements[9] +
			Elements[4] * Elements[1] * Elements[11] -
			Elements[4] * Elements[3] * Elements[9] -
			Elements[8] * Elements[1] * Elements[7] +
			Elements[8] * Elements[3] * Elements[5];

		temp[15] = Elements[0] * Elements[5] * Elements[10] -
			Elements[0] * Elements[6] * Elements[9] -
			Elements[4] * Elements[1] * Elements[10] +
			Elements[4] * Elements[2] * Elements[9] +
			Elements[8] * Elements[1] * Elements[6] -
			Elements[8] * Elements[2] * Elements[5];

		float determinant = Elements[0] * temp[0] + Elements[1] * temp[4] + Elements[2] * temp[8] + Elements[3] * temp[12];
		determinant = 1.0f / determinant;

		for (int i = 0; i < 4 * 4; i++)
			Elements[i] = temp[i] * determinant;

		return *this;
	}

	Vec3 operator*(const Mat4 & left, const Vec3 & right)
	{
		return left.Multiply(right);
	}

	Vec4 operator*(const Mat4 & left, const Vec4 & right)
	{
		return left.Multiply(right);
	}


	Vec3 Mat4::Multiply(const Vec3 & other) const
	{
		return Vec3(
			Columns[0].x * other.x + Columns[1].x * other.y + Columns[2].x * other.z + Columns[3].x,
			Columns[0].y * other.x + Columns[1].y * other.y + Columns[2].y * other.z + Columns[3].y,
			Columns[0].w * other.x + Columns[1].z * other.y + Columns[2].z * other.z + Columns[3].z
		);
	}

	Vec4 Mat4::Multiply(const Vec4 & other) const
	{
		return Vec4(
			Columns[0].x * other.x + Columns[1].x * other.y + Columns[2].x * other.z + Columns[3].x * other.w,
			Columns[0].y * other.x + Columns[1].y * other.y + Columns[2].y * other.z + Columns[3].y * other.w,
			Columns[0].w * other.x + Columns[1].z * other.y + Columns[2].z * other.z + Columns[3].z * other.w,
			Columns[0].z * other.x + Columns[1].w * other.y + Columns[2].w * other.z + Columns[3].w * other.w
		);
	}

	Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Mat4 Result(1.0f);

		Result.Elements[0 + 0 * 4] = 2.0f / (right - left);
		Result.Elements[1 + 1 * 4] = 2.0f / (top - bottom);
		Result.Elements[2 + 2 * 4] = 2.0f / (near - far);
		
		Result.Elements[0 + 3 * 4] = (left + right) / (left - right);
		Result.Elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		Result.Elements[2 + 3 * 4] = (far + near) / (far - near);

		return Result;
	}

	Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far)
	{
		Mat4 Result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;

		float b = (near + far) / (near - far);
		float c = (2.f * near + far) / (near - far);

		Result.Elements[0 + 0 * 4] = a;
		Result.Elements[1 + 1 * 4] = q;
		Result.Elements[2 + 2 * 4] = b;
		Result.Elements[3 + 2 * 4] = -1.0f;
		Result.Elements[2 + 3 * 4] = c;


		return Result;
	}

	Mat4 Mat4::Translation(const Vec3& translation)
	{
		Mat4 Result(1.0f);

		Result.Elements[0 + 3 * 4] = translation.x;
		Result.Elements[1 + 3 * 4] = translation.y;
		Result.Elements[2 + 3 * 4] = translation.z;

		return Result;
	}

	Mat4 Mat4::Rotation(float angle, const Vec3 & axis)
	{
		Mat4 Result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		Result.Elements[0 + 0 * 4] = x * omc + c;
		Result.Elements[1 + 0 * 4] = y * x * omc + z * s;
		Result.Elements[2 + 0 * 4] = x * z * omc - y * s;

		Result.Elements[0 + 1 * 4] = x * y * omc - z * s;
		Result.Elements[1 + 1 * 4] = y * omc + c;
		Result.Elements[2 + 1 * 4] = y * z * omc + x * s;

		Result.Elements[0 + 2 * 4] = x * z * omc + y * s;
		Result.Elements[1 + 2 * 4] = y * z * omc - x * s;
		Result.Elements[2 + 2 * 4] = z * omc + c;


		return Result;
	}

	Mat4 Mat4::Scale(const Vec3 & scale)
	{
		Mat4 Result(1.0f);

		Result.Elements[0 + 0 * 4] = scale.x;
		Result.Elements[1 + 1 * 4] = scale.y;
		Result.Elements[2 + 2 * 4] = scale.z;

		return Result;
	}

	void Mat4::ShowMat4()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int a = 0; a < 4; a++)
			{
				std::cout << Elements[a + i * 4] << ", ";
			}
			std::cout << std::endl;
		}
	}






	//END
} }