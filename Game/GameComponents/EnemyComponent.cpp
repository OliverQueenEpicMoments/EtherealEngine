#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize() {
    CharacterComponent::Initialize();
}

void EnemyComponent::Update() {
    auto actor = m_Owner->GetScene()->GetActorFromName("Player");
    if (actor) {
        Ethrl::Vector2 direction = actor->m_Transform.Position - m_Owner->m_Transform.Position;
        Ethrl::Vector2 force = direction.Normalized() * Speed;

        auto component = m_Owner->GetComponent<Ethrl::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(Ethrl::Actor* other) {
    if (other->GetTag() == "Player") {
        Ethrl::Event event;
        event.Name = "EVENT_DAMAGE";
        event.Data = Damage;
        event.Reciever = other;
        Ethrl::g_EventManager.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(Ethrl::Actor* other) {

}

void EnemyComponent::OnNotify(const Ethrl::Event& event) {
    if (event.Name == "EVENT_DAMAGE") {
        Health -= std::get<float>(event.Data);
        if (Health <= 0) {
            m_Owner->SetDestroy();
        }
    }
}

bool EnemyComponent::Write(const rapidjson::Value& value) const {
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value) {
    CharacterComponent::Read(value);

    return true;
}