#include "PhysicsComponent.h"
#include "Engine.h"

namespace Ethrl {
	void PhysicsComponent::Update() {
		m_Velocity += m_Acceleration * g_Time.DeltaTime;
		m_Owner->m_Transform.Position += m_Velocity * g_Time.DeltaTime;
		//m_Velocity *= m_Damping;

		m_Acceleration = Vector2::Zero;
	}
}