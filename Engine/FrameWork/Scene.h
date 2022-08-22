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
		~Scene() = default;

		void Initialize() override;
		void Update() override;
		void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

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
}