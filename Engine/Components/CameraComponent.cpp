#include "CameraComponent.h"
#include "FrameWork/Actor.h"
#include "Engine.h"

namespace Ethrl {
    void CameraComponent::Initialize() {
        SetViewport(ViewportSize);
    }

    void CameraComponent::Update() {
        Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(-m_Owner->m_Transform.Position);
        Matrix3x3 mxRotation = Matrix3x3::CreateRotation(-Math::DegToRad(m_Owner->m_Transform.Rotation));

        m_View = mxTranslation * mxRotation;

        g_Renderer.SetViewMatrix(m_View);
    }

    void CameraComponent::SetViewport(const Vector2& Size) {
        Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(Size * 0.5f);

        m_Viewport = mxTranslation;
        g_Renderer.SetViewportMatrix(m_Viewport);
    }

    bool CameraComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool CameraComponent::Read(const rapidjson::Value& value) {
        READ_DATA(value, ViewportSize);

        return true;
    }
}