#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace Ethrl {
	class Scene;
	class Renderer;

	class Actor : public GameObject {
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_Transform{ transform } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* Other) {}

		float GetRadius() { return 0; // return m_Model.GetRadius() * std::max(m_Transform.Scale.X, m_Transform.Scale.Y); 
		}
		std::string& GetTag() { return m_Tag; }

		friend class Scene;
		friend class Component;

		Transform m_Transform;

	protected:
		std::string m_Tag;
		bool m_Destroy = false;

		// Physics
		Vector2 m_Velocity;
		float m_Damping = 1.0f;

		Scene* m_Scene = nullptr;
		std::vector<std::unique_ptr<Component>> m_Components;
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