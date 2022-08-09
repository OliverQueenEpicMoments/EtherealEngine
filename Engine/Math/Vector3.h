#pragma once
#include <cmath>

namespace Ethrl {
	struct Vector3 {
		float X, Y, Z;

		Vector3() : X{ 0 }, Y{ 0 }, Z{ 0 } {}
		Vector3(float X, float Y, float Z) : X{ X }, Y{ Y }, Z{ Z } {}
		Vector3(float V) : X{ V }, Y{ V }, Z{ V } {}
		Vector3(int X, int Y, int Z) : X{ (float)X }, Y{ (float)Y }, Z{ (float)Z } {};

		void Set(float X, float Y, float Z) { this->X = X; this->Y = Y; this->Z = Z; }
		float operator [] (size_t Index) const { return (&X)[Index]; }
		float& operator [] (size_t Index) { return (&X)[Index]; }


		// Arithmetic Operators
		// V2 = V2 + V2
		Vector3 operator + (const Vector3& V) const { return Vector3{ this->X + V.X, this->Y + V.Y, this->Z + V.Z }; }
		Vector3 operator - (const Vector3& V) const { return Vector3{ this->X - V.X, this->Y - V.Y, this->Z - V.Z }; }
		Vector3 operator * (const Vector3& V) const { return Vector3{ this->X * V.X, this->Y * V.Y, this->Z * V.Z }; }
		Vector3 operator / (const Vector3& V) const { return Vector3{ this->X / V.X, this->Y / V.Y, this->Z / V.Z }; }

		// V2 = V2 + Float
		Vector3 operator + (float S) const { return Vector3{ this->X + S, this->Y + S, this->Z + S }; }
		Vector3 operator - (float S) const { return Vector3{ this->X - S, this->Y - S, this->Z - S }; }
		Vector3 operator * (float S) const { return Vector3{ this->X * S, this->Y * S, this->Z * S }; }
		Vector3 operator / (float S) const { return Vector3{ this->X / S, this->Y / S, this->Z / S }; }

		Vector3& operator += (const Vector3& V) { this->X += V.X, this->Y += V.Y, this->Z += V.Z; return *this; }
		Vector3& operator -= (const Vector3& V) { this->X -= V.X, this->Y -= V.Y, this->Z -= V.Z; return *this; }
		Vector3& operator *= (const Vector3& V) { this->X *= V.X, this->Y *= V.Y, this->Z *= V.Z; return *this; }
		Vector3& operator /= (const Vector3& V) { this->X /= V.X, this->Y /= V.Y, this->Z /= V.Z; return *this; }

		Vector3& operator += (float S) { this->X += S, this->Y += S, this->Z += S; return *this; }
		Vector3& operator -= (float S) { this->X -= S, this->Y -= S, this->Z -= S; return *this; }
		Vector3& operator *= (float S) { this->X *= S, this->Y *= S, this->Z *= S; return *this; }
		Vector3& operator /= (float S) { this->X /= S, this->Y /= S, this->Z /= S; return *this; }

		// Unary
		// V2 = -V2
		Vector3  operator - () { return Vector3(-X, -Y, -Z); }

		// Comparison
		bool operator == (const Vector3& V) const { return (this->X == V.X && this->Y == V.Y && this->Z == V.Z); }
		bool operator != (const Vector3& V) const { return (this->X != V.X || this->Y != V.Y || this->Z != V.Z); }

		// Functions
		float LengthSquared();
		float Length();

		float DistanceSquared(const Vector3& V);
		float Distance(const Vector3& V);

		Vector3 Normalized();
		void Normalize();
	};

	inline float Vector3::LengthSquared() { return X * X + Y * Y + Z * Z; }
	inline float Vector3::Length() { return std::sqrt(X * X + Y * Y + Z * Z); }
	inline float Vector3::DistanceSquared(const Vector3& V) { return ((*this) - V).LengthSquared(); }
	inline float Vector3::Distance(const Vector3& V) { return ((*this) - V).Length(); }

	inline Vector3 Vector3::Normalized() {
		float length = Length();

		return (length == 0) ? Vector3{ 0, 0, 0 } : Vector3{ X / length, Y / length, Z / length };
	}

	inline void Vector3::Normalize() { (*this) /= Length(); }
}