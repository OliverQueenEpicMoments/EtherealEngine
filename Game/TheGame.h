#pragma once
#include"FrameWork/Game.h"

class TheGame : public Ethrl::Game {
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(Ethrl::Renderer& renderer) override;
};