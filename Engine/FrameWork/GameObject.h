#pragma once
#include "../Math/Transform.h"

namespace Ethrl {
	class GameObject {
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}