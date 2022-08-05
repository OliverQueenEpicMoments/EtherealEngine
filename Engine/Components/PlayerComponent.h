#pragma once
#include "FrameWork/Component.h"

namespace Ethrl {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;
		void Update() override;
	};
}