#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/AudioComponent.h>
#include <Components/PhysicsComponent.h>

namespace Ethrl {
	void PlayerComponent::Initialize() {
		CharacterComponent::Initialize();
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

		Vector2 VelocityX;
		auto component = m_Owner->GetComponent<PhysicsComponent>();
		if (component) {
			component->ApplyForce(Direction * Speed);
			VelocityX = component->Velocity;
		} 

		// Jump
		if (g_InputSystem.GetKeyState(Ethrl::Key_Space) == InputSystem::State::Pressed) {
			auto component = m_Owner->GetComponent<PhysicsComponent>();
			if (component) {
				component->ApplyForce(Vector2::Up * 500);
			}
		}

		auto rendercomponent = m_Owner->GetComponent<RenderComponent>();
		if (rendercomponent) {
			if (VelocityX.X != 0) rendercomponent->SetHorizontalFlip(VelocityX.X < 0);
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other) {
		if (other->GetName() == "Coin") {
			Event event;
			event.Name = "EVENT_ADD_POINTS";
			event.Data = 100;

			g_EventManager.Notify(event);

			other->SetDestroy();
		} 

		if (other->GetTag() == "Enemy") {
			Event event;
			event.Name = "EVENT_DAMAGE";
			event.Data = Damage;
			event.Reciever = other;

			g_EventManager.Notify(event);
			other->SetDestroy();
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other) {}

	bool PlayerComponent::Write(const rapidjson::Value& value) const {
		return false;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value) {
		CharacterComponent::Read(value);
		READ_DATA(value, Jump);

		return true;
	}

	void PlayerComponent::OnNotify(const Event& event) {
		if (event.Name == "EVENT_DAMAGE") {
			Health -= std::get<float>(event.Data);
			std::cout << "Health: " << Health << std::endl;
			if (Health <= 0) {
				m_Owner->SetDestroy();

				Event event;
				event.Name = "EVENT_PLAYER_DEAD";

				g_EventManager.Notify(event);
			}
		}
		/*if (event.Name == "EVENT_HEALTH") {
			Health += std::get<float>(event.Data);
		}*/
	}
}