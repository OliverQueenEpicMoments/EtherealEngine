#pragma once
#include "box2d/b2_world.h"
#include <memory>

namespace Ethrl {
	class PhysicsSystem {
	public:
		PhysicsSystem() = default;
		~PhysicsSystem() = default;

		void initialize();
		void Shutdown();

		void Update();

	private:
		std::unique_ptr<b2World> World;
	};
}