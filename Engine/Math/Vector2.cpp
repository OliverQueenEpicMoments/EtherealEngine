#include "Vector2.h"

namespace Ethrl {
	const Vector2 Vector2::One{1, 1};
	const Vector2 Vector2::Zero{0, 0};
	const Vector2 Vector2::Up{0, -1};
	const Vector2 Vector2::Down{0, 1};
	const Vector2 Vector2::Left{-1, 0};
	const Vector2 Vector2::Right{1, 0};

	std::istream& operator >> (std::istream& stream, Vector2& V) {
		std::string Line;
		std::getline(stream, Line);

		std::string XS = Line.substr(Line.find("{") + 1, Line.find(",") - (Line.find("{") + 1));
		V.X = std::stof(XS);

		std::string YS = Line.substr(Line.find(",") + 1, Line.find("}") - (Line.find(",") + 1));
		V.Y = std::stof(YS);

		return stream;
	}

	std::ostream& operator << (std::ostream& stream, const Vector2& V) {
		stream << V.X << " " << V.Y;

		return stream;
	}
}