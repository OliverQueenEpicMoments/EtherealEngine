#pragma once

#include "RenderComponent.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include <memory>

namespace Ethrl {
	class Font;
	class Texture;
	class TextComponent : public RenderComponent {
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		void SetText(const std::string& text);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::string Text;
		std::string FontName;
		int FontSize;
		Vector2 Registration;
		Color color;

		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture> m_Texture;
	};
}