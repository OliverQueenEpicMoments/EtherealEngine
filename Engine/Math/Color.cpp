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
		Str = Line.substr(Line.find("{") + 1, Line.find(",") - (Line.find("{") + 1));
		color.R = (uint8_t)(std::stof(Str) * 255);
		std::cout << color.R;

		Line = Line.substr(Line.find(",") + 1);

		// Green 
		Str = Line.substr(0, Line.find(","));
		color.G = (uint8_t)(std::stof(Str) * 255);
		std::cout << color.G;

		// Blue 
		Str = Line.substr(Line.find(",") + 1, Line.find("}") - (Line.find(",") + 1));
		color.B = (uint8_t)(std::stof(Str) * 255);
		std::cout << color.B;

		color.A = 255;

		return stream;
	}

	std::ostream& operator << (std::ostream& stream, const Color& color) {
		stream << (int)color.R << " " << (int)color.G << " " << (int)color.B << " " << (int)color.A;

		return stream;
	}
}