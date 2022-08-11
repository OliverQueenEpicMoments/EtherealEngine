#pragma once
#include "RenderComponent.h"

namespace Ethrl {
	class Model;
	class ModelComponent : public RenderComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Model> m_Model;
	};
}