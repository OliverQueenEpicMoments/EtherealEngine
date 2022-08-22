#include "PhysicsSystem.h"
#include "Math/MathUtils.h"

namespace Ethrl {
	const float PhysicsSystem::PixelsPerUnit = 48.0f;

	void PhysicsSystem::initialize() {
		b2Vec2 Gravity{ 0, 10 };
		m_World = std::make_unique<b2World>(Gravity);
	}

	void PhysicsSystem::Shutdown() {

	}

	void PhysicsSystem::Update() {
		m_World->Step(1.0f / 60.0f, 8, 3);
	}

	b2Body* PhysicsSystem::CreateBody(const Vector2& position, float angle, const RigidBodyData& data) {
		Vector2 worldPosition = ScreenToWorld(position);

		b2BodyDef bodyDef;
		bodyDef.type = (data.IsDynamic) ? b2_dynamicBody : b2_staticBody;
		bodyDef.position = *((b2Vec2*)(&worldPosition));
		bodyDef.angle = Math::DegToRad(angle);
		bodyDef.fixedRotation = data.ConstrainAngle;
		b2Body* body = m_World->CreateBody(&bodyDef);

		return body;
	}

	void PhysicsSystem::DestroyBody(b2Body* body) {
		m_World->DestroyBody(body);
	}
}