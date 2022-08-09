#pragma once
#include "Vector2.h"
#include "Math/Matrix2x2.h"
#include "Math/MathUtils.h"

namespace Ethrl {
	struct Transform {
		Vector2 Position;
		float Rotation{ 0 };
		Vector2 Scale{ 1, 1 };

		operator Matrix2x2 () const {
			Matrix2x2 mxScale = Matrix2x2::CreateScale(Scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRotation(Math::DegToRad(Rotation));

			return { mxScale * mxRotation };
		}
	};
}