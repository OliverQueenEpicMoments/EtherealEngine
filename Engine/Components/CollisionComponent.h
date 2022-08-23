#pragma once
#include "FrameWork/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"

namespace Ethrl {
	class CollisionComponent : public Component, public ICollision {
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData Data;
	};
}