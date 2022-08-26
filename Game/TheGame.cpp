#include "TheGame.h"
#include "Engine.h"

void TheGame::Initialize() {
	m_Scene = std::make_unique<Ethrl::Scene>();

	rapidjson::Document document;
	std::vector<std::string> SceneNames = {"Scenes/Prefabs.txt", "Scenes/Tilemap.txt", "Scenes/Level.txt"};

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
}

void TheGame::Shutdown() {
	m_Scene->RemoveAll();
}

void TheGame::Update() {
	m_Scene->Update();
}

void TheGame::Draw(Ethrl::Renderer& renderer) {
	m_Scene->Draw(renderer);
}