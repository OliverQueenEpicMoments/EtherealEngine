#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include <Math/Vector2.h>

namespace Ethrl {
	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;
		void Update() override;

		virtual void ApplyForce(const Vector2& Force) { Acceleration += Force; }

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 Velocity;
		Vector2 Acceleration;

		float Damping = 0.99f;
	};
}