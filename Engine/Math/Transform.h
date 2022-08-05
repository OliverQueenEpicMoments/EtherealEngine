#pragma once
#include "Vector2.h"

namespace Ethrl {
	struct Transform
	{
		Vector2 Position;
		float Rotation{ 0 };
		Vector2 Scale{ 1, 1 };
	};
}