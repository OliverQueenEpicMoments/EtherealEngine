#pragma once
#include"Renderer.h"
#include "Resource/Resource.h"
#include <vector>
#include <string>

namespace Ethrl {
	class Model : public Resource {
	public:
		Model() = default;
		Model(std::vector<Ethrl::Vector2>& points, const Ethrl::Color& color) :
			m_points{ points },
			m_color{ color }{};

		Model(const std::string& FileName);

		bool Create(std::string FileName, ...) override;

		void Draw(Renderer& renderer, const Vector2& position, float Angle, const Vector2& Scale = {1, 1});
		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& FileName);
		float CalculateRadius();

		float GetRadius() { return m_Radius; };

	private:
		Ethrl::Color m_color{0, 0, 0, 0};
		std::vector<Ethrl::Vector2> m_points;

		float m_Radius = 0;
	};
}