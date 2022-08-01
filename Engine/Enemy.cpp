#include "Enemy.h"
#include "Engine.h"
#include "Bullet.h"
#include "../Game/Player.h"

void Enemy::Initialize() {
	m_FireTimer = Ethrl::Random(2, 3);
	m_Speed = Ethrl::Random(40, 150);
}

void Enemy::Update() {
	m_FireTimer -= Ethrl::g_Time.DeltaTime;
	if (m_FireTimer <= 0) {
		m_FireTimer = Ethrl::Random(1, 4);
		Ethrl::Transform transform = m_Transform;
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Ethrl::Model{ "Bullet.txt" }, transform);
		bullet->GetTag() = "Enemy";
		m_Scene->Add(std::move(bullet));
	}

	// Set Rotation to Player
	Player* player = m_Scene->GetActor<Player>();
	if (player) {
		Ethrl::Vector2 direction = player->m_Transform.Position - m_Transform.Position;
		m_Transform.Rotation = direction.GetAngle();
	}

	// Calculate Velocity
	Ethrl::Vector2 Direction{ 1, 0 };
	Direction = Ethrl::Vector2::Rotate(Direction, m_Transform.Rotation);
	Ethrl::Vector2 Velocity = Direction * m_Speed * Ethrl::g_Time.DeltaTime;

	// Move
	m_Transform.Position += Velocity;

	// Wrap
	if (m_Transform.Position.X > Ethrl::g_Renderer.GetWidth()) m_Transform.Position.X = 0;
	if (m_Transform.Position.X < 0) m_Transform.Position.X = (float)Ethrl::g_Renderer.GetWidth();

	if (m_Transform.Position.Y > Ethrl::g_Renderer.GetWidth()) m_Transform.Position.Y = 0;
	if (m_Transform.Position.Y < 0) m_Transform.Position.Y = (float)Ethrl::g_Renderer.GetWidth();
}

void Enemy::OnCollision(Actor* Other) {
	if (dynamic_cast<Bullet*>(Other) && Other->GetTag() == "Player") {
		m_Health -= dynamic_cast<Bullet*>(Other)->GetDamage();

		if (m_Health <= 0) {
			m_Destroy = true;
			Ethrl::g_AudioSystem.PlayAudio("Explosion2");
			m_Scene->GetGame()->AddPoints(50);
		}
	}
}
