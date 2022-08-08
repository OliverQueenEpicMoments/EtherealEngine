#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include <Math/Vector2.h>

namespace Ethrl {
	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;
		void Update() override;

		void ApplyForce(const Vector2& Force) { m_Acceleration += Force; }

	public:
		Vector2 m_Velocity;
		Vector2 m_Acceleration;

		float m_Damping = 1;
	};
}