#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"

namespace Ethrl {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float Speed = 300.0f;
	};
}