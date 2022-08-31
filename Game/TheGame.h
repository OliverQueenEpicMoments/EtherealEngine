#pragma once
#include"FrameWork/Game.h"
#include "FrameWork/Event.h"

class TheGame : public Ethrl::Game, public Ethrl::INotify {
public:
	enum class GameState {
		TitleScreen,
		StartLevel,
		Game,
		PlayerDeath,
		GameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Ethrl::Renderer& renderer) override;
	virtual void OnNotify(const Ethrl::Event& event) override;

	void OnAddPoints(const Ethrl::Event& event_);
	void OnPlayerDeath(const Ethrl::Event& event_);

private:
	GameState m_GameState = GameState::TitleScreen;
	float m_StateTimer = 0;
	int m_Lives = 3;

	// Inherited via INotify
};