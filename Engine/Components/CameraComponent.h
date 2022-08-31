#pragma once
#include "FrameWork/Component.h"
#include "Math/Matrix3x3.h"

namespace Ethrl {
	class CameraComponent : public Component {
	public:
		CLASS_DECLARATION(CameraComponent)

		virtual void Initialize() override;
		virtual void Update() override;

		const Matrix3x3& GetView() { return m_View; }

		void SetViewport(const Vector2& Size);
		const Matrix3x3& GetViewport() { return m_Viewport; }
		
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 ViewportSize;

		Matrix3x3 m_View;
		Matrix3x3 m_Viewport;
	};
}