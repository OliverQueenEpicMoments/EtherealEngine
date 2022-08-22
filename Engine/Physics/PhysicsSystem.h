#pragma once
#include "box2d/b2_world.h"
#include "box2d/box2d.h"
#include "Math/Vector2.h"
#include <memory>

#define VECTOR2_TO_B2VEC2(Vec) (*(b2Vec2*)(&Vec))
#define B2VEC2_TO_VECTOR2(Vec) (*(Ethrl::Vector2*)(&Vec))

namespace Ethrl {
	class PhysicsSystem {
	public:
		struct RigidBodyData {
			float GravityScale = 1.0f;
			bool ConstrainAngle = false;
			bool IsDynamic = true;
		};

		struct CollisionData {
			Vector2 Size;
			float Density = 1.0f;
			float Friction = 1.0f;
			float Restitution = 0.3f;
			bool IsTrigger = false;
		};

	public:
		PhysicsSystem() = default;
		~PhysicsSystem() = default;

		void initialize();
		void Shutdown();

		void Update();

		b2Body* CreateBody(const Vector2& position, float angle, const RigidBodyData& data);
		void DestroyBody(b2Body* body);

		static Vector2 WorldToScreen(const Vector2& world) { return world * PixelsPerUnit; }
		static Vector2 ScreenToWorld(const Vector2& screen) { return screen * (1.0f / PixelsPerUnit); }

	private:
		static const float PixelsPerUnit;

		std::unique_ptr<b2World> m_World;
	};
}