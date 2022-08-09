#pragma once
#include "Vector3.h"

namespace Ethrl {
	struct Matrix3x3 {
		Vector3 Rows[3]; // [3][3][3]

		Matrix3x3() = default;
		Matrix3x3(const Vector3& Row1, const Vector3& Row2, const Vector3& Row3);

		Vector3 operator [] (size_t Index) const { return Rows[Index]; }
		Vector3& operator [] (size_t Index) { return Rows[Index]; }

		Vector3 operator * (const Vector3& V); // MX3x3 * V3
		Matrix3x3 operator * (const Matrix3x3& mx); // MX3x3 * MX3x3

		static Matrix3x3 CreateScale(const Vector3& Scale);
		static Matrix3x3 CreateScale(float Scale);
		static Matrix3x3 CreateRotation(float Radians);

		static const Matrix3x3 Identity;
		static const Matrix3x3 Zero;
	};

	inline Matrix3x3::Matrix3x3(const Vector3& Row1, const Vector3& Row2, const Vector3& Row3) {
		Rows[0] = Row1;
		Rows[1] = Row2;
		Rows[2] = Row3;
	}

	inline Vector3 Matrix3x3::operator*(const Vector3& V) {
		Vector3 Result;



		return Result;
	}

	inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3& mx) {
		return Matrix3x3();
	}

	inline Matrix3x3 Matrix3x3::CreateScale(const Vector3& Scale) {
		return Matrix3x3();
	}

	inline Matrix3x3 Matrix3x3::CreateScale(float Scale) {
		return Matrix3x3();
	}

	inline Matrix3x3 Matrix3x3::CreateRotation(float Radians) {
		return Matrix3x3();
	}
}