#pragma once

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

	int SQR(int V);
	inline int Half(int V) { return V / 2; }
}