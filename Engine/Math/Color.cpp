#include "Color.h"

namespace Ethrl {
	const Color Color::White{255, 255, 255, 255};
	const Color Color::Black{0, 0, 0, 255};
	const Color Color::Red{255, 0, 0, 255};
	const Color Color::Green{0, 255, 0, 255};
	const Color Color::Blue{0, 0, 255, 255};

	std::istream& operator >> (std::istream& stream, Color& color) {
		std::string Line;
		std::getline(stream, Line);

		std::string Str;

		// Red
		Str = Line.substr(2, 1);
		//Str = Line.substr(Line.find("{") + 1, Line.find(",") - 1);
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