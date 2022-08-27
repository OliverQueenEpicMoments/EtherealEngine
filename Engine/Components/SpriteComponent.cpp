#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"
#include <Engine.h>

namespace Ethrl {
	void SpriteComponent::Update() {

	}

	void SpriteComponent::Draw(Renderer& renderer) {
		renderer.Draw(m_Texture, source, m_Owner->m_Transform);
	}

	bool SpriteComponent::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool SpriteComponent::Read(const rapidjson::Value& value) {
		std::string SpriteName;
		READ_DATA(value, SpriteName);

		m_Texture = g_Resources.Get<Texture>(SpriteName, g_Renderer);

		if (!READ_DATA(value, source)) {
			source.X = 0;
			source.Y = 0;
			source.W = (int)m_Texture->GetSize().X;
			source.H = (int)m_Texture->GetSize().Y;
		}
		return true;
	}
}