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

		// Check Collision
		for (auto Iter1 = m_Actors.begin(); Iter1 != m_Actors.end(); Iter1++) {
			for (auto Iter2 = m_Actors.begin(); Iter2 != m_Actors.end(); Iter2++) {
				if (Iter1 == Iter2) continue;

				float Radius = (* Iter1)->GetRadius() + (*Iter2)->GetRadius();
				float Distance = (*Iter1)->m_Transform.Position.Distance((*Iter2)->m_Transform.Position);

				if (Distance < Radius) {
					(*Iter1)->OnCollision((*Iter2).get());
					(*Iter2)->OnCollision((*Iter1).get());
				}
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
				Add(std::move(actor));
			}
		}
		return true;
	}

	void Scene::Add(std::unique_ptr<Actor> actor) {
		actor->m_Scene = this;
		m_Actors.push_back(std::move(actor));
	}
}
