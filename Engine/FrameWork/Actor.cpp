#include "Actor.h"
#include "Components/RenderComponent.h"

namespace Ethrl {
	void Actor::Update() {
		for (auto &component : m_Components) {
			component->Update();
		}
	}

	void Actor::Draw(Renderer& renderer) {
		for (auto& component : m_Components) {
			auto rendercomponent = dynamic_cast<RenderComponent*> (component.get());
			if (rendercomponent) {
				rendercomponent->Draw(renderer);
			}
		}
	}

	void Actor::AddComponent(std::unique_ptr<Component> component) {
		component->m_Owner = this;
		m_Components.push_back(std::move(component));
	}
}