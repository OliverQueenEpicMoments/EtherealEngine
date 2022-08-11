#include "Actor.h"
#include "Components/RenderComponent.h"

namespace Ethrl {
	void Actor::Update() {
		for (auto &component : m_Components) {
			component->Update();
		}

		for (auto& child : m_Children) {
			child->Update();
		}

		if (m_Parent) m_Transform.Update(m_Parent->m_Transform.matrix);
		else m_Transform.Update();
	}

	void Actor::Draw(Renderer& renderer) {
		for (auto& component : m_Components) {
			auto rendercomponent = dynamic_cast<RenderComponent*> (component.get());
			if (rendercomponent) {
				rendercomponent->Draw(renderer);
			}
		}

		for (auto& child : m_Children) {
			child->Draw(renderer);
		}
	}

	void Actor::AddChild(std::unique_ptr<Actor> child) {
		child->m_Parent = this;
		child->m_Scene = this->m_Scene;

		m_Children.push_back(std::move(child));
	}

	void Actor::AddComponent(std::unique_ptr<Component> component) {
		component->m_Owner = this;
		m_Components.push_back(std::move(component));
	}
}