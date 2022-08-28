#pragma once
#include <cmath>

namespace Math {
	constexpr float Pi = 3.14159265359f; // 180
	constexpr float PiDouble = 6.28318530718f; // 360
	constexpr float HalfPi = 1.57079632679f; // 90

	constexpr float DegToRad(float Degrees) {
		return Degrees * (Pi / 180);
	}

	constexpr float RadToDeg(float Radians) {
		return Radians * (180 / Pi);
	}

	template <typename T>
	T Clamp(T Value, T Min, T Max) {
		if (Value < Min) return Min;
		if (Value > Max) return Max;

		return Value;
	}

	template <typename T>
	T Lerp(T Min, T Max, float t) {
		t = Clamp(t, 0.0f, 1.0f);

		return Min + ((Max - Min) * t);
	}

	template <typename T>
	T Normalize(T Value, T Min, T Max) {
		return (Value - Min) / (Max - Min);
	}

	template <typename T>
	T Remap(T Value, T InMin, T InMax, T OutMin, T OutMax) {
		return Lerp(OutMin, OutMax, Normalize(Value, InMin, InMax));
	}

	template <typename T>
	T Mod(T Numerator, T Denominator) {
		return std::fmod(Numerator, Denominator);
	}

	template <>
	inline int Mod(int Numerator, int Denominator) {
		return Numerator % Denominator;
	}

	template <typename T>
	T Wrap(T Value, T Min, T Max) {
		if (Value < Min) return Max - Mod((Min - Value), (Max - Min));
		if (Value > Max) return Min + Mod((Value - Min), (Max - Min));

		return Value;
	}
}