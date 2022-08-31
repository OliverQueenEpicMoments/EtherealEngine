#include "PhysicsSystem.h"
#include "Math/MathUtils.h"

namespace Ethrl {
	const float PhysicsSystem::PixelsPerUnit = 48.0f;

	void PhysicsSystem::initialize() {
		b2Vec2 Gravity{ 0, 10 };
		m_World = std::make_unique<b2World>(Gravity);
		m_ContactListener = std::make_unique<ContactListener>();
		m_World->SetContactListener(m_ContactListener.get());
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

	void PhysicsSystem::SetCollisionBox(b2Body* body, const CollisionData& data, Actor* actor) {
		b2PolygonShape shape;
		Vector2 worldSize = PhysicsSystem::ScreenToWorld(data.Size * 0.5f);
		shape.SetAsBox(worldSize.X, worldSize.Y);

		b2FixtureDef fixtureDef;
		fixtureDef.density = data.Density;
		fixtureDef.friction = data.Friction;
		fixtureDef.restitution = data.Restitution;
		fixtureDef.isSensor = data.IsTrigger;
		fixtureDef.shape = &shape;
		fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(actor);

		body->CreateFixture(&fixtureDef);
	}

	void PhysicsSystem::SetCollisionBoxStatic(b2Body* body, const CollisionData& data, Actor* actor) {
		Vector2 WorldSize = PhysicsSystem::ScreenToWorld(data.Size * 0.5f);

		b2Vec2 VS[4] = {
			{ -WorldSize.X, -WorldSize.Y },
			{  WorldSize.X, -WorldSize.Y },
			{  WorldSize.X,  WorldSize.Y },
			{ -WorldSize.X,  WorldSize.Y },
		};

		b2ChainShape Shape;
		Shape.CreateLoop(VS, 4);

		b2FixtureDef FixtureDef;
		FixtureDef.density = data.Density;
		FixtureDef.friction = data.Friction;
		FixtureDef.restitution = data.Restitution;
		FixtureDef.isSensor = data.IsTrigger;
		FixtureDef.shape = &Shape;
		FixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(actor);

		body->CreateFixture(&FixtureDef);
	}
}