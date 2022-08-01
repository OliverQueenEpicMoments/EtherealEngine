#include "Model.h"
#include "../Core/File.h"
#include <sstream>
#include <iostream>

namespace Ethrl {
	Model::Model(const std::string& FileName) {
		Load(FileName);
		m_Radius = CalculateRadius();
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float Angle, float Scale) {
		// Draw Model
		for (int I = 0; I < m_points.size() - 1; I++) {
			Ethrl::Vector2 P1 = Vector2::Rotate((m_points[I] * Scale), Angle) + position;
			Ethrl::Vector2 P2 = Vector2::Rotate((m_points[I + 1] * Scale), Angle) + position;

			renderer.DrawLine(P1, P2, m_color);
		}
	}

	void Model::Load(const std::string& FileName) {
		std::string Buffer;

		Ethrl::ReadFile(FileName, Buffer);

		// Read Color
		std::istringstream stream(Buffer);
		stream >> m_color;

		// Read Number of Points
		std::string Line;
		std::getline(stream, Line);
		size_t NumPoints = std::stoi(Line);

		// Read Model Points
		for (size_t I = 0; I < NumPoints; I++) {
			Vector2 Point;

			stream >> Point;
			m_points.push_back(Point);
		}
	}

	float Model::CalculateRadius() {
		float Radius = 0;

		// Find the largest length
		for (auto& Point : m_points) {
			if (Point.Length() > Radius) Radius = Point.Length();
		}

		return Radius;
	}
}