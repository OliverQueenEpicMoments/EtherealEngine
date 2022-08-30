#include "TheGame.h"
#include "Engine.h"

void TheGame::Initialize() {
	m_Scene = std::make_unique<Ethrl::Scene>();

	rapidjson::Document document;
	std::vector<std::string> SceneNames = { "Scenes/Prefabs.txt", "Scenes/Tilemap.txt", "Scenes/Level.txt" };

	for (std::string SceneName : SceneNames) {
		bool success = Ethrl::Json::Load(SceneName, document);
		if (!success) {
			LOG("Could not load sxene %s", SceneName.c_str());
			continue;
		}
		m_Scene->Read(document);
	}

	m_Scene->Initialize();

	Ethrl::g_EventManager.Subscribe("Event Add Points", std::bind(&TheGame::OnAddPoints, this, std::placeholders::_1));
}

void TheGame::Shutdown() {
	m_Scene->RemoveAll();
}

void TheGame::Update() {
	switch (m_GameState) {
	case GameState::TitleScreen:
		if (Ethrl::g_InputSystem.GetKeyState(Ethrl::Key_Space) == Ethrl::InputSystem::State::Pressed) {
			//m_Scene->GetActorFromName("Title")->SetActive(false);

			m_GameState = GameState::StartLevel;
		}
		break;

	case GameState::StartLevel:
		for (int i = 0; i < 10; i++) {
			auto actor = Ethrl::Factory::Instance().Create<Ethrl::Actor>("Coin");
			actor->m_Transform.Position = { Ethrl::RandomF(0, 800), 100.0f };
			actor->Initialize();

			m_Scene->Add(std::move(actor));
		}
		m_GameState = GameState::Game;
		break;

	case GameState::Game:
		break;

	case GameState::PlayerDeath:
		m_StateTimer -= Ethrl::g_Time.DeltaTime;
		if (m_StateTimer) m_GameState = (m_Lives > 0) ? GameState::StartLevel : GameState::GameOver;
		break;

	case GameState::GameOver:
		break;

	default:
		break;
	}
	m_Scene->Update();
}

void TheGame::Draw(Ethrl::Renderer& renderer) {
	m_Scene->Draw(renderer);
}

void TheGame::OnAddPoints(const Ethrl::Event& event_) {
	AddPoints(std::get<int>(event_.Data));

	std::cout << event_.Name << std::endl;
	std::cout << GetScore() << std::endl;
}

void TheGame::OnPlayerDeath(const Ethrl::Event& event_) {
	m_GameState = GameState::PlayerDeath;
	m_StateTimer = 3;
}