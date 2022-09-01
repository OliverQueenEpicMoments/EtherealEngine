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
			//Direction = Vector2::Up;
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
		if (m_GroundCount > 0 && g_InputSystem.GetKeyState(Ethrl::Key_Space) == InputSystem::State::Pressed) {
			auto component = m_Owner->GetComponent<PhysicsComponent>();
			if (component) {
				component->ApplyForce(Vector2::Up * 500);
			}
		}

		Vector2 VelocityX;
		auto component = m_Owner->GetComponent<PhysicsComponent>();
		if (component) {
			float Multiplier = (m_GroundCount > 0) ? 1 : 0.2f;

			component->ApplyForce(Direction * Speed);
			VelocityX = component->Velocity;
		} 

		// Animations
		auto AnimComponent = m_Owner->GetComponent<SpriteAnimComponent>();
		if (AnimComponent) {
			if (VelocityX.X != 0) AnimComponent->SetHorizontalFlip(VelocityX.X < 0);
			if (std::fabs(VelocityX.X) > 0) {
				AnimComponent->SetSequence("Run");
			} else {
				AnimComponent->SetSequence("Idle");
			}
		} 

		// Set Camera
		auto Camera = m_Owner->GetScene()->GetActorFromName("Camera");
		if (Camera) Camera->m_Transform.Position = Math::Lerp(Camera->m_Transform.Position, m_Owner->m_Transform.Position, 10 * g_Time.DeltaTime);
	}

	void PlayerComponent::OnCollisionEnter(Actor* other) {
		if (other->GetTag() == "Ground") {
			m_GroundCount++;
			std::cout << m_GroundCount << std::endl;
		}

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

	void PlayerComponent::OnCollisionExit(Actor* other) {
		if (other->GetTag() == "Ground") {
			m_GroundCount--;
			std::cout << m_GroundCount << std::endl;
		}
	}

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
	}
}