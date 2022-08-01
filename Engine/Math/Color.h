#pragma once
#include <cstdint>
#include <sstream>

namespace Ethrl {
	struct Color {
		uint8_t R;
		uint8_t G;
		uint8_t B;
		uint8_t A;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color) {
		std::string Line;
		std::getline(stream, Line);

		std::string Str;

		// Red
		Str = Line.substr(2, 1);
		float Red = std::stof(Str);
		color.R = (uint8_t)(Red * 255);

		Line = Line.substr(Line.find(",") + 1);

		// Green 
		Str = Line.substr();
		float Green = std::stof(Str);
		color.G = (uint8_t)(Green * 255);

		Line = Line.substr(Line.find(",") + 1);

		// Blue 
		Str = Line.substr();
		float Blue = std::stof(Str);
		color.B = (uint8_t)(Blue * 255);

		color.A = 255;

		return stream;
	}
}