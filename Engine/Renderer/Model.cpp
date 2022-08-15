#include "Model.h"
#include "../Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"

#include <sstream>
#include <iostream>

namespace Ethrl {
	Model::Model(const std::string& FileName) {
		Load(FileName);
		m_Radius = CalculateRadius();
	}

	bool Model::Create(std::string FileName, ...) {
		if (!Load(FileName)) {
			LOG("Error could not create file %s", FileName.c_str());

			return false;
		}
		return true;
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float Angle, const Vector2& Scale) {
		// Draw Model
		for (int I = 0; I < m_points.size() - 1; I++) {
			Ethrl::Vector2 P1 = Vector2::Rotate((m_points[I] * Scale), Angle) + position;
			Ethrl::Vector2 P2 = Vector2::Rotate((m_points[I + 1] * Scale), Angle) + position;

			renderer.DrawLine(P1, P2, m_color);
		}
	}

	void Model::Draw(Renderer& renderer, const Transform& transform) {
		// Draw Model
		Matrix3x3 mx = transform.matrix;
		 
		//if (m_points.size() == 0) return;

		for (int I = 0; I < m_points.size() - 1; I++) {
			Ethrl::Vector2 P1 = mx * m_points[I];
			Ethrl::Vector2 P2 = mx * m_points[I + 1];

			renderer.DrawLine(P1, P2, m_color);
		}
	}

	bool Model::Load(const std::string& FileName) {
		std::string Buffer;

		if (!Ethrl::ReadFile(FileName, Buffer)) {
			LOG("Error could not read file %s", FileName.c_str());
			return false;
		}

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
		return true;
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