#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Ethrl {
	// Forward Declaration
	class Actor;
	class Renderer;
	class Game;

	class Scene : public GameObject, public ISerializable {
	public:
		Scene() = default;
		Scene(Game* game) : m_Game{ game } {}
		Scene(const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)

		void Initialize() override;
		void Update() override;
		void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		template<typename T>
		T* GetActor();

		template<typename T = Actor>
		T* GetActorFromName(const std::string& Name);

		template<typename T = Actor>
		std::vector<T*> GetActorsFromTag(const std::string& Tag);

		Game* GetGame() { return m_Game; };

	private:
		Game* m_Game;
		std::list <std::unique_ptr <Actor>> m_Actors;
	};

	template<typename T>
	inline T* Scene::GetActor() {
		for (auto& actor : m_Actors) {
			T* Result = dynamic_cast<T*>(actor.get());
			
			if (Result) return Result;
		}
		return nullptr;
	}

	template<typename T>
	inline T* Scene::GetActorFromName(const std::string& Name) {
		for (auto& actors : m_Actors) {
			if (actors->GetName() == Name) {
				return dynamic_cast<T*>(actors.get());
			}
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Scene::GetActorsFromTag(const std::string& Tag) {
		std::vector<T*> result;
		for (auto& actors : m_Actors) {
			if (actors->GetTag() == Tag) {
				T* TagActor = dynamic_cast<T*>(actors.get());
				if (TagActor) result.push_back(TagActor); 
				//if (TagActor) result.push_back(std::move(TagActor));
			}
		}
		return result;
	}
}