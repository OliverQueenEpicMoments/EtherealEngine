#pragma once
#include "Vector2.h"

namespace Ethrl {
	struct Matrix2x2 {
		Vector2 Rows[2]; // [2][2]

		Matrix2x2() = default;
		Matrix2x2(const Vector2& Row1, const Vector2& Row2);

		Vector2 operator [] (size_t Index) const { return Rows[Index]; }
		Vector2& operator [] (size_t Index) { return Rows[Index]; }

		Vector2 operator * (const Vector2& V); // MX2x2 * V2
		Matrix2x2 operator * (const Matrix2x2& mx); // MX2x2 * MX2x2

		static Matrix2x2 CreateScale(const Vector2& Scale);
		static Matrix2x2 CreateScale(float Scale);
		static Matrix2x2 CreateRotation(float Radians);

		static const Matrix2x2 Identity;
		static const Matrix2x2 Zero;
	};

	inline Matrix2x2::Matrix2x2(const Vector2& Row1, const Vector2& Row2) {
		Rows[0] = Row1;
		Rows[1] = Row2;
	}

	inline Vector2 Matrix2x2::operator*(const Vector2& V) {
		Vector2 Result;

		Result.X = V.X * Rows[0][0] + V.Y * Rows[0][1];
		Result.Y = V.X * Rows[1][0] + V.Y * Rows[1][1];

		return Result;
	}

	inline Matrix2x2 Matrix2x2::operator*(const Matrix2x2& mx) {
		Matrix2x2 Result;

		Result[0][0] = Rows[0][0] * mx[0][0] + Rows[0][1] * mx[1][0];
		Result[0][1] = Rows[0][0] * mx[0][1] + Rows[0][1] * mx[1][1];
		Result[1][0] = Rows[1][0] * mx[0][0] + Rows[1][1] * mx[1][0];
		Result[1][1] = Rows[1][0] * mx[0][1] + Rows[1][1] * mx[1][1];

		return Result;
	}

	inline Matrix2x2 Matrix2x2::CreateScale(const Vector2& Scale) {
		Matrix2x2 MX;
		
		// Non-Uniform Scale
		MX[0] = Vector2{Scale.X, 0.0f};
		MX[1] = Vector2{0.0f, Scale.Y};

		return MX;
	}

	inline Matrix2x2 Matrix2x2::CreateScale(float Scale) {
		Matrix2x2 MX;

		// Uniform Scale
		MX[0] = Vector2{ Scale, 0.0f };
		MX[1] = Vector2{ 0.0f, Scale };

		return MX;
	}

	inline Matrix2x2 Matrix2x2::CreateRotation(float Radians) {
		Matrix2x2 MX;

		MX[0] = Vector2{ std::cos(Radians), -std::sin(Radians) };
		MX[1] = Vector2{ std::sin(Radians), std::cos(Radians) };

		return MX;
	}
}