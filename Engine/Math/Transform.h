#pragma once
#include "Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"
#include "Serialization/ISerializable.h"

namespace Ethrl {
	struct Transform : public ISerializable {
		Vector2 Position;
		float Rotation{ 0 };
		Vector2 Scale{ 1, 1 };

		Matrix3x3 matrix;

		Transform() = default;
		Transform(const Vector2& position, float rotation, const Vector2& scale) :
			Position{ position },
			Rotation{ rotation },
			Scale{ scale }
		{}

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update() {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(Scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(Rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(Position);

			matrix = { mxTranslation * mxRotation * mxScale };
		}

		void Update(const Matrix3x3& parent) {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(Scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(Rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(Position);

			matrix = { mxTranslation * mxRotation * mxScale };
			matrix = parent * matrix;
		}

		operator Matrix2x2 () const {
			Matrix2x2 mxScale = Matrix2x2::CreateScale(Scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRotation(Math::DegToRad(Rotation));

			return { mxScale * mxRotation };
		}

		operator Matrix3x3 () const {
			Matrix3x3 mxScale = Matrix3x3::CreateScale(Scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(Math::DegToRad(Rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(Position);

			return { mxTranslation * mxRotation * mxScale };
		}
	};
}