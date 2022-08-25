#include "Scene.h"
#include "Actor.h"
#include "Factory.h"
#include <algorithm>
#include <iostream>

namespace Ethrl {
	void Scene::Initialize() {
		for (auto& actor : m_Actors) { actor->Initialize(); }
	}

	void Scene::Update() {
		auto Iter = m_Actors.begin();
		while (Iter != m_Actors.end()) {
			(*Iter)->Update();
			if ((*Iter)->m_Destroy) {
				Iter = m_Actors.erase(Iter);
			} else {
				Iter++;
			}
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_Actors) {
			actor->Draw(renderer);
		}
	}

	bool Scene::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool Scene::Read(const rapidjson::Value& value) {
		if (!value.HasMember("actors") || !value["actors"].IsArray()) {
			return false;
		}

		// Read Actors
		for (auto& actorvalue : value["actors"].GetArray()) {
			std::string type;
			READ_DATA(actorvalue, type);

			auto actor = Factory::Instance().Create<Actor>(type);
			if (actor) {
				// Read Actor
				actor->Read(actorvalue);

				bool prefab = false;
				READ_DATA(actorvalue, prefab);

				if (prefab) {
					std::string Name = actor->GetName();
					Factory::Instance().RegisterPrefab(Name, std::move(actor));
				}
				else {
					Add(std::move(actor));
				}

				
			}
		}
		return true;
	}

	void Scene::Add(std::unique_ptr<Actor> actor) {
		actor->m_Scene = this;
		m_Actors.push_back(std::move(actor));
	}

	void Scene::RemoveAll() {
		m_Actors.clear();
	}
}
