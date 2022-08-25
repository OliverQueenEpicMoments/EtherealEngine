#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Physics/Collision.h"

namespace Ethrl {
	class PlayerComponent : public Component, public ICollision {
	public:
		PlayerComponent() = default;

		CLASS_DECLARATION(PlayerComponent)

		void Initialize() override;
		void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float Speed = 300.0f;
	};
}