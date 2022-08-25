#pragma once
#include "RenderComponent.h"

namespace Ethrl {
	class Model;
	class ModelComponent : public RenderComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		CLASS_DECLARATION(ModelComponent)

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::shared_ptr<Model> m_Model;
	};
}