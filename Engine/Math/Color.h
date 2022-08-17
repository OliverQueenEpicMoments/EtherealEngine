#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace Ethrl {
	struct Color {
		uint8_t R;
		uint8_t G;
		uint8_t B;
		uint8_t A;

		uint8_t operator [] (size_t Index) const { return (&R)[Index]; }
		uint8_t& operator [] (size_t Index) { return (&R)[Index]; }

		static const Color White;
		static const Color Black;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
	};

	std::istream& operator >> (std::istream& stream, Color& color);
	std::ostream& operator << (std::ostream& stream, const Color& color);
}