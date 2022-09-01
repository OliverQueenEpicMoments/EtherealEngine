#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Physics/Collision.h"
#include "CharacterComponent.h"

namespace Ethrl {
	class PlayerComponent : public CharacterComponent {
	public:
		PlayerComponent() = default;

		CLASS_DECLARATION(PlayerComponent)

		void Initialize() override;
		void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnNotify(const Event& event) override;

	public:
		float Jump = 3000.0f;

		int m_GroundCount = 0;
	};
}