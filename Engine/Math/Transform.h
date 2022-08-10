#pragma once
#include "Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"

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

		operator Matrix3x3 () const {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(Scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(Rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(Position);

			return { mxScale * mxRotation * mxTranslation };
		}
	};
}