#pragma once
#include <cstdint>
#include <sstream>
#include <string>

namespace Ethrl {
	struct Color {
		uint8_t R;
		uint8_t G;
		uint8_t B;
		uint8_t A;

		static const Color White;
		static const Color Black;
		static const Color Red;
		static const Color Green;
		static const Color Blue;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	std::istream& operator >> (std::istream& stream, Color& color);
}