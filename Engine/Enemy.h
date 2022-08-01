#pragma once
#include "FrameWork/Actor.h"

class Enemy : public Ethrl::Actor {
public:
	Enemy() = default;
	Enemy(const Ethrl::Model& model, const Ethrl::Transform transform, float Health) :
		Actor{ model, transform }, m_Health{Health} {
		Initialize();
	}

	void Initialize();
	void Update() override;

	void OnCollision(Actor* Other) override;

private:
	float m_Health = 5;
	float m_Speed = 50;

	float m_FireTimer = 4;
};