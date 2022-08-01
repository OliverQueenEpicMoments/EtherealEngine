#pragma once
#include "FrameWork/Actor.h"

class Bullet : public Ethrl::Actor {
public:
	Bullet() = default;
	Bullet(const Ethrl::Model& model, const Ethrl::Transform transform, float Damage = 1) :
		Actor{ model, transform }, 
		m_Damage{Damage}{}

	void Update() override;
	void OnCollision(Actor* Other) override;

	float GetDamage() { return m_Damage; }

private:
	float m_Damage = 1;
	float m_Speed = 200;
	float m_LifeSpan = 2.5f;
};