#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/AudioComponent.h>
#include <Components/PhysicsComponent.h>

namespace Ethrl {
	void PlayerComponent::Update() {
		Vector2 Direction = Vector2::Zero;

		// Update transform with input
		float Thrust = 0;
		if (g_InputSystem.GetKeyState(Ethrl::Key_W) == InputSystem::State::Held) {
			//Direction = Vector2::Up;

			Thrust = Speed;
		}

		auto component = m_Owner->GetComponent<PhysicsComponent>();
		if (component) {
			// Thrust Force
			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_Owner->m_Transform.Rotation)) * Thrust;
			component->ApplyForce(force);

			// Gravity Well
			force = (Vector2{400, 300} - m_Owner->m_Transform.Position).Normalized() * 75;
			component->ApplyForce(force);
		} 

		if (g_InputSystem.GetKeyState(Ethrl::Key_A) == InputSystem::State::Held) {
			Direction = Vector2::Left;

			m_Owner->m_Transform.Rotation -= 180 * g_Time.DeltaTime;
		}

		if (g_InputSystem.GetKeyState(Ethrl::Key_S) == InputSystem::State::Held) {
			Direction = Vector2::Down;
		}

		if (g_InputSystem.GetKeyState(Ethrl::Key_D) == InputSystem::State::Held) {
			//Direction = Vector2::Right;

			m_Owner->m_Transform.Rotation += 180 * g_Time.DeltaTime;
		}

		//m_Owner->m_Transform.Position += Direction * 300 * g_Time.DeltaTime;

		// Shoot
		if (g_InputSystem.GetKeyState(Ethrl::Key_Space) == InputSystem::State::Pressed) {
			auto component = m_Owner->GetComponent<AudioComponent>();
			if (component) {
				component->Play("Laser", false);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const {
		return false;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value) {
		READ_DATA(value, Speed);

		return true;
	}
}