#include "CharacterComponent.h"
#include "Engine.h"

namespace Ethrl {
	CharacterComponent::~CharacterComponent() {
		g_EventManager.Unsubscribe("EVENT_DAMAGE", m_Owner);

	}

	void CharacterComponent::Initialize() {
		g_EventManager.Subscribe("EVENT_DAMAGE", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_Owner);
		g_EventManager.Subscribe("EVENT_PICKUP", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_Owner);
		g_EventManager.Subscribe("EVENT_HEALTH", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_Owner);

		auto component = m_Owner->GetComponent<CollisionComponent>();
		if (component) {
			component->SetCollisionEnter(std::bind(&CharacterComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&CharacterComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	bool CharacterComponent::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool CharacterComponent::Read(const rapidjson::Value& value) {
		READ_DATA(value, Health);
		READ_DATA(value, Damage);
		READ_DATA(value, Speed);

		return true;
	}
}