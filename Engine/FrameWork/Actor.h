#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace Ethrl {
	class Scene;
	class Renderer;

	class Actor : public GameObject, public ISerializable {
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_Transform{ transform } {}

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void AddChild(std::unique_ptr<Actor> child);

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* Other) {}

		float GetRadius() { return 0; // return m_Model.GetRadius() * std::max(m_Transform.Scale.X, m_Transform.Scale.Y); 
		}

		const std::string& GetTag() { return tag; }
		void SetTag(const std::string& tag) { this->tag = tag; }

		const std::string& GetName() { return name; }
		void SetName(const std::string& name) { this->name = name; }

		friend class Scene;
		friend class Component;

		Transform m_Transform;

	protected:
		std::string name;
		std::string tag;

		bool m_Destroy = false;

		// Physics
		Vector2 m_Velocity;
		float m_Damping = 1.0f;

		Scene* m_Scene = nullptr;
		Actor* m_Parent = nullptr;

		std::vector<std::unique_ptr<Component>> m_Components;
		std::vector<std::unique_ptr<Actor>> m_Children;
	};

	template<typename T>
	inline T* Actor::GetComponent() {
		for (auto& Component : m_Components) {
			T* Result = dynamic_cast<T*>(Component.get());
			if (Result) return (Result);
		}

		return nullptr;
	}
}