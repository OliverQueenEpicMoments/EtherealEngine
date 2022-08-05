#pragma once
#include "RenderComponent.h"

namespace Ethrl {
	class Texture;
	class SpriteComponent : public RenderComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Texture> m_Texture;
	};
}