#include "RBPhysicsComponent.h"
#include "Engine.h"

namespace Ethrl {
	RBPhysicsComponent::~RBPhysicsComponent() {
		if (m_Body) {
			g_PhysicsSystem.DestroyBody(m_Body);
		}
	}

	void RBPhysicsComponent::Initialize() {
		m_Body = g_PhysicsSystem.CreateBody(m_Owner->m_Transform.Position, m_Owner->m_Transform.Rotation, Data);
		m_Body->SetGravityScale(Data.GravityScale);
		m_Body->SetLinearDamping(Damping);
	}

	void RBPhysicsComponent::Update() {
		Vector2 position = B2VEC2_TO_VECTOR2(m_Body->GetPosition());
		m_Owner->m_Transform.Position = PhysicsSystem::WorldToScreen(position);
		m_Owner->m_Transform.Rotation = Math::RadToDeg(m_Body->GetAngle());

		Velocity = B2VEC2_TO_VECTOR2(m_Body->GetLinearVelocity());
	}

	void RBPhysicsComponent::ApplyForce(const Vector2& Force) {
		b2Vec2 V{ Force.X, Force.Y };
		m_Body->ApplyForceToCenter(VECTOR2_TO_B2VEC2(Force), true);
	}

	bool RBPhysicsComponent::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool RBPhysicsComponent::Read(const rapidjson::Value& value) {
		PhysicsComponent::Read(value);

		READ_DATA(value, Data.GravityScale);
		READ_DATA(value, Data.ConstrainAngle);
		READ_DATA(value, Data.IsDynamic);

		return true;
	}
}