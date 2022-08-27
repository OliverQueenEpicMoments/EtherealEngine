#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/AudioComponent.h>
#include <Components/PhysicsComponent.h>

namespace Ethrl {
	void PlayerComponent::Initialize() {
		auto component = m_Owner->GetComponent<CollisionComponent>();
		if (component) {
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update() {
		Vector2 Direction = Vector2::Zero;

		// Update transform with input
		float Thrust = 0;
		if (g_InputSystem.GetKeyState(Ethrl::Key_W) == InputSystem::State::Held) {
			Direction = Vector2::Up;
		}

		if (g_InputSystem.GetKeyState(Ethrl::Key_A) == InputSystem::State::Held) {
			Direction = Vector2::Left;
		}

		if (g_InputSystem.GetKeyState(Ethrl::Key_S) == InputSystem::State::Held) {
			Direction = Vector2::Down;
		}

		if (g_InputSystem.GetKeyState(Ethrl::Key_D) == InputSystem::State::Held) {
			Direction = Vector2::Right;
		}

		// Jump
		if (g_InputSystem.GetKeyState(Ethrl::Key_Space) == InputSystem::State::Pressed) {
			auto component = m_Owner->GetComponent<PhysicsComponent>();
			if (component) {
				component->ApplyForce(Vector2::Up * 500);
			}
		}

		auto component = m_Owner->GetComponent<PhysicsComponent>();
		if (component) {
			component->ApplyForce(Direction * Speed);
		} 
	}

	void PlayerComponent::OnCollisionEnter(Actor* other) {
		if (other->GetName() == "Coin") other->SetDestroy();

		std::cout << "Player Enter" << std::endl; // 15/16 minutes
	}

	void PlayerComponent::OnCollisionExit(Actor* other) {
		std::cout << "Player Exit" << std::endl;
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const {
		return false;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value) {
		READ_DATA(value, Speed);

		return true;
	}
}