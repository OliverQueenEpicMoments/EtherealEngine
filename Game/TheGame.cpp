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

	for (int i = 0; i < 10; i++) {
		auto actor = Ethrl::Factory::Instance().Create<Ethrl::Actor>("Coin");
		actor->m_Transform.Position = { Ethrl::RandomF(0, 800), 100.0f };
		actor->Initialize();

		m_Scene->Add(std::move(actor));
	}
	//Ethrl::g_EventManager.Subscribe("Event Add Points", std::bind(&TheGame::OnAddPoints, this, std::placeholders::_1));
}

void TheGame::Shutdown() {
	m_Scene->RemoveAll();
}

void TheGame::Update() {
	switch (m_GameState)
	{
	case TheGame::GameState::TitleScreen:

		break;
	case TheGame::GameState::StartLevel:

		break;
	case TheGame::GameState::Game:

		break;
	case TheGame::GameState::PlayerDeath:

		break;
	case TheGame::GameState::GameOver:

		break;
	default:

		break;
	}

	m_Scene->Update();
}

void TheGame::Draw(Ethrl::Renderer& renderer) {
	m_Scene->Draw(renderer);
}

/*void TheGame::OnAddPoints(const Ethrl::Event& event_) {
	AddPoints(std::get<int>(event_.Data));

	std::cout << event_.Name << std::endl;
	std::cout << GetScore() << std::endl;
}

void TheGame::OnPlayerDeath(const Ethrl::Event& event_) {
	m_GameState = GameState::PlayerDeath;
	m_StateTimer = 3;
}*/