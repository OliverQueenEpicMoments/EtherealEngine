#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"

namespace Ethrl {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;
		void Update() override;
	};
}