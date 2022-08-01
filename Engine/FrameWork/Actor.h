#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace Ethrl {
	class Scene;

	class Actor : public GameObject {
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : 
			GameObject{ transform }, 
			m_Model{ model } {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);
		virtual void OnCollision(Actor* Other) {}

		float GetRadius() { return m_Model.GetRadius() * m_Transform.Scale; }
		std::string& GetTag() { return m_Tag; }

		friend class Scene;

	protected:
		std::string m_Tag;
		bool m_Destroy = false;

		// Physics
		Vector2 m_Velocity;
		float m_Damping = 1.0f;

		Scene* m_Scene = nullptr;
		Model m_Model;
	};
} 