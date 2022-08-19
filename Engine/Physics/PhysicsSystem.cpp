#include "PhysicsSystem.h"

namespace Ethrl {
	void PhysicsSystem::initialize() {
		b2Vec2 Gravity{ 0, 10 };
		World = std::make_unique<b2World>(Gravity);
	}

	void PhysicsSystem::Shutdown() {

	}

	void PhysicsSystem::Update() {

	}
}