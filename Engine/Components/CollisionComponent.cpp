#include "CollisionComponent.h"
#include "Engine.h"
#include <iostream>

namespace Ethrl {
    void CollisionComponent::Initialize() {
        auto component = m_Owner->GetComponent<RBPhysicsComponent>();
        if (component) {
            if (Data.Size.X == 0 && Data.Size.Y == 0) {
                auto rendercomponent = m_Owner->GetComponent<RenderComponent>();
                if (rendercomponent) {
                    Data.Size = Vector2{rendercomponent->GetSource().W, rendercomponent->GetSource().H};
                }
            }
            Data.Size = Data.Size * ScaleOffset;// * m_Owner->m_Transform.Scale;

            if (component->m_Body->GetType() == b2_staticBody) {
                g_PhysicsSystem.SetCollisionBoxStatic(component->m_Body, Data, m_Owner);
            } else {
                g_PhysicsSystem.SetCollisionBox(component->m_Body, Data, m_Owner);
            }
        }
    }

    void CollisionComponent::Update() {

    }

    void CollisionComponent::OnCollisionEnter(Actor* other) {
        if (m_EnterFunction) m_EnterFunction(other);
    }

    void CollisionComponent::OnCollisionExit(Actor* other) {
        if (m_EnterFunction) m_ExitFunction(other);
    }

    bool CollisionComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool CollisionComponent::Read(const rapidjson::Value& value) {
        READ_DATA(value, Data.Size);
        READ_DATA(value, Data.Density);
        READ_DATA(value, Data.Friction);
        READ_DATA(value, Data.Restitution);
        READ_DATA(value, Data.IsTrigger);
        READ_DATA(value, ScaleOffset);

        return true;
    }
}