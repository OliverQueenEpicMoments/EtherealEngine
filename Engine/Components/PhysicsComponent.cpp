#include "PhysicsComponent.h"
#include "Engine.h"

namespace Ethrl {
	void PhysicsComponent::Update() {
		Velocity += Acceleration * g_Time.DeltaTime;
		m_Owner->m_Transform.Position += Velocity * g_Time.DeltaTime;
		Velocity *= Damping;

		Acceleration = Vector2::Zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const {


		return true;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value) {
		READ_DATA(value, Damping);
		READ_DATA(value, Velocity);
		READ_DATA(value, Acceleration);

		return true;
	}
}