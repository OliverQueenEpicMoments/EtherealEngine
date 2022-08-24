#pragma once
#include "FrameWork/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
#include <functional>

namespace Ethrl {
	class CollisionComponent : public Component, public ICollision {
	public:
		using FunctionPtr = std::function<void(Actor*)>;

	public:
		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		void SetCollisionEnter(FunctionPtr function) { m_EnterFunction = function; }
		void SetCollisionExit(FunctionPtr function) { m_ExitFunction = function; }

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData Data;
		FunctionPtr m_EnterFunction;
		FunctionPtr m_ExitFunction;
	};
}