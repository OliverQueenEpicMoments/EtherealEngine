#pragma once
#include <cmath>
#include <sstream>
#include <string>

namespace Ethrl {
	struct Vector2 {
		float X, Y;

		Vector2() : X{ 0 }, Y{ 0 } {}
		Vector2(float X, float Y) : X{ X }, Y{ Y } {}
		Vector2(float V) : X{ V }, Y{ V } {}
		Vector2(int X, int Y) : X{ (float)X }, Y{ (float)Y } {};

		void Set(float X, float Y) { this->X = X; this->Y = Y; }

		// Arithmetic Operators
		// V2 = V2 + V2
		Vector2 operator + (const Vector2& V) const { return Vector2{ this->X + V.X, this->Y + V.Y }; }
		Vector2 operator - (const Vector2& V) const { return Vector2{ this->X - V.X, this->Y - V.Y }; }
		Vector2 operator * (const Vector2& V) const { return Vector2{ this->X * V.X, this->Y * V.Y }; }
		Vector2 operator / (const Vector2& V) const { return Vector2{ this->X / V.X, this->Y / V.Y }; }

		// V2 = V2 + Float
		Vector2 operator + (float S) const { return Vector2{ this->X + S, this->Y + S }; }
		Vector2 operator - (float S) const { return Vector2{ this->X - S, this->Y - S }; }
		Vector2 operator * (float S) const { return Vector2{ this->X * S, this->Y * S }; }
		Vector2 operator / (float S) const { return Vector2{ this->X / S, this->Y / S }; }

		Vector2& operator += (const Vector2& V) { this->X += V.X, this->Y += V.Y; return *this; }
		Vector2& operator -= (const Vector2& V) { this->X -= V.X, this->Y -= V.Y; return *this; }
		Vector2& operator *= (const Vector2& V) { this->X *= V.X, this->Y *= V.Y; return *this; }
		Vector2& operator /= (const Vector2& V) { this->X /= V.X, this->Y /= V.Y; return *this; }

		Vector2& operator += (float S) { this->X += S, this->Y += S; return *this; }
		Vector2& operator -= (float S) { this->X += S, this->Y += S; return *this; }
		Vector2& operator *= (float S) { this->X += S, this->Y += S; return *this; }
		Vector2& operator /= (float S) { this->X += S, this->Y += S; return *this; }

		// Unary
		// V2 = -V2
		Vector2  operator - () { return Vector2(-X, -Y); }
		
		// Comparison
		bool operator == (const Vector2& V) const { return (this->X == V.X && this->Y == V.Y); }
		bool operator != (const Vector2& V) const { return (this->X != V.X || this->Y != V.Y); }

		// Functions
		float LengthSquared();
		float Length();

		float DistanceSquared(const Vector2& V);
		float Distance(const Vector2& V);

		Vector2 Normalized();
		void Normalize();

		float GetAngle();
		static Vector2 Rotate(const Vector2& V, float Angle);

		static const Vector2 One;
		static const Vector2 Zero;
		static const Vector2 Up;
		static const Vector2 Down;
		static const Vector2 Left;
		static const Vector2 Right;
	};

	std::istream& operator >> (std::istream& stream, Vector2& V);

	inline float Vector2::LengthSquared() { return X * X + Y * Y; }
	inline float Vector2::Length() { return std::sqrt(X * X + Y * Y); }
	inline float Vector2::DistanceSquared(const Vector2& V) {
		return ((*this) - V).LengthSquared();
	}

	inline float Vector2::Distance(const Vector2& V) {
		return ((*this) - V).Length();
	}

	inline Vector2 Vector2::Normalized() {
		float length = Length();

		return Vector2{X / length, Y / length};
	}

	inline void Vector2::Normalize() {
		(*this) /= Length();
	}

	inline float Vector2::GetAngle() {
		return std::atan2(Y, X);
	}

	inline Vector2 Vector2::Rotate(const Vector2& V, float Angle) {
		float X = V.X * std::cos(Angle) - V.Y * std::sin(Angle);
		float Y = V.X * std::sin(Angle) + V.Y * std::cos(Angle);

		return Vector2(X, Y);
	}
}