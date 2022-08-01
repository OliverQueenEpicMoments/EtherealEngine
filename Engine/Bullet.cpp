#include "Bullet.h"
#include "Engine.h"
#include "../Game/Player.h"
#include "Enemy.h"
#include "../Game/Interceptor.h"
#include "../Game/Asteroid.h"

void Bullet::Update() {
	// Self-Destruct
	m_LifeSpan -= Ethrl::g_Time.DeltaTime;
	if (m_LifeSpan <= 0) m_Destroy = true;

	// Velocity
	Ethrl::Vector2 Direction{ 1, 0 };
	Direction = Ethrl::Vector2::Rotate(Direction, m_Transform.Rotation);
	Ethrl::Vector2  Velocity = Direction * m_Speed * Ethrl::g_Time.DeltaTime;

	// Move
	m_Transform.Position += Velocity;

	// Wrap
	if (m_Transform.Position.X > Ethrl::g_Renderer.GetWidth()) m_Transform.Position.X = 0;
	if (m_Transform.Position.X < 0) m_Transform.Position.X = (float)Ethrl::g_Renderer.GetWidth();

	if (m_Transform.Position.Y > Ethrl::g_Renderer.GetWidth()) m_Transform.Position.Y = 0;
	if (m_Transform.Position.Y < 0) m_Transform.Position.Y = (float)Ethrl::g_Renderer.GetWidth();
}

void Bullet::OnCollision(Actor* Other) {
	if (dynamic_cast<Player*>(Other) && m_Tag != "Player") {
		m_Destroy = true;
	}

	if (dynamic_cast<Enemy*>(Other) && m_Tag != "Enemy") {
		m_Destroy = true;
	}

	if (dynamic_cast<Asteroid*>(Other) && m_Tag != "Asteroid") {
		m_Destroy = true;
	}

	if (dynamic_cast<Interceptor*>(Other) && m_Tag != "Interceptor") {
		m_Destroy = true;
	}
}
