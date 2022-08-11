#pragma once
#include "Vector3.h"
#include "Vector2.h"

namespace Ethrl {
	struct Matrix3x3 {
		Vector3 Rows[3]; // [3][3] Rows / Columns

		Matrix3x3() = default;
		Matrix3x3(const Vector3& Row1, const Vector3& Row2, const Vector3& Row3);

		Vector3 operator [] (size_t Index) const { return Rows[Index]; }
		Vector3& operator [] (size_t Index) { return Rows[Index]; }

		Vector2 operator * (const Vector2& V) const; // M2x2 * V2
		Matrix3x3 operator * (const Matrix3x3& mx) const; // MX3x3 * MX3x3

		static Matrix3x3 CreateScale(const Vector2& Scale);
		static Matrix3x3 CreateScale(float Scale);
		static Matrix3x3 CreateRotation(float Radians);
		static Matrix3x3 CreateTranslation(const Vector2& translate);

		static const Matrix3x3 Identity;
		static const Matrix3x3 Zero;
	};

	inline Matrix3x3::Matrix3x3(const Vector3& Row1, const Vector3& Row2, const Vector3& Row3) {
		Rows[0] = Row1;
		Rows[1] = Row2;
		Rows[2] = Row3;
	}

	inline Vector2 Matrix3x3::operator*(const Vector2& V) const {
		Vector2 Result;

		Result.X = V.X * Rows[0][0] + V.Y * Rows[0][1] + Rows[0][2];
		Result.Y = V.X * Rows[1][0] + V.Y * Rows[1][1] + Rows[1][2];

		return Result;
	}

	inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3& mx) const {
		Matrix3x3 Result;

		// Row 1
		Result[0][0] = Rows[0][0] * mx[0][0] + Rows[0][1] * mx[1][0] + Rows[0][2] * mx[2][0];
		Result[0][1] = Rows[0][0] * mx[0][1] + Rows[0][1] * mx[1][1] + Rows[0][2] * mx[2][1];
		Result[0][2] = Rows[0][0] * mx[0][2] + Rows[0][1] * mx[1][2] + Rows[0][2] * mx[2][2];

		// Row 2
		Result[1][0] = Rows[1][0] * mx[0][0] + Rows[1][1] * mx[1][0] + Rows[1][2] * mx[2][0];
		Result[1][1] = Rows[1][0] * mx[0][1] + Rows[1][1] * mx[1][1] + Rows[1][2] * mx[2][1];
		Result[1][2] = Rows[1][0] * mx[0][2] + Rows[1][1] * mx[1][2] + Rows[1][2] * mx[2][2];

		// Row 3
		Result[2][0] = Rows[2][0] * mx[0][0] + Rows[2][1] * mx[1][0] + Rows[2][2] * mx[2][0];
		Result[2][1] = Rows[2][0] * mx[0][1] + Rows[2][1] * mx[1][1] + Rows[2][2] * mx[2][1];
		Result[2][2] = Rows[2][0] * mx[0][2] + Rows[2][1] * mx[1][2] + Rows[2][2] * mx[2][2];

		return Result;
	}

	inline Matrix3x3 Matrix3x3::CreateScale(const Vector2& Scale) {
		Matrix3x3 MX = Identity;

		// Non-Uniform Scale
		MX[0][0] = Scale.X;
		MX[1][1] = Scale.Y;

		return MX;
	}

	inline Matrix3x3 Matrix3x3::CreateScale(float Scale) {
		Matrix3x3 MX = Identity;

		// Uniform Scale
		MX[0][0] = Scale;
		MX[1][1] = Scale;

		return MX;
	}

	inline Matrix3x3 Matrix3x3::CreateRotation(float Radians) {
		Matrix3x3 MX;

		MX[0] = Vector3{ std::cos(Radians), -std::sin(Radians), 0.0f };
		MX[1] = Vector3{ std::sin(Radians), std::cos(Radians), 0.0f };
		MX[2] = Vector3{ 0.0f, 0.0f, 1.0f };

		return MX;
	}

	inline Matrix3x3 Matrix3x3::CreateTranslation(const Vector2& translate) {
		Matrix3x3 MX = Identity;

		MX[0][2] = translate.X;
		MX[1][2] = translate.Y;

		return MX;
	}
}