#include "Actor.h"
#include "Factory.h"
#include "Components/RenderComponent.h"

namespace Ethrl {
	void Actor::Initialize() {
		for (auto& component : m_Components) { component->Initialize(); }
		for (auto& child : m_Children) { child->Initialize(); }
	}

	void Actor::Update() {
		for (auto &component : m_Components) { component->Update(); }
		for (auto& child : m_Children) { child->Update(); }

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

	bool Actor::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool Actor::Read(const rapidjson::Value& value) {
		READ_DATA(value, tag);
		READ_DATA(value, name);

		m_Transform.Read(value["transform"]);

		if (value.HasMember("components") && value["components"].IsArray()) {
			for (auto& componentvalue : value["components"].GetArray()) {
				std::string type;
				READ_DATA(componentvalue, type);

				auto component = Factory::Instance().Create<Component>(type);
				if (component) {
					component->Read(componentvalue);
					AddComponent(std::move(component));
				}
			}
		}
		return true;
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