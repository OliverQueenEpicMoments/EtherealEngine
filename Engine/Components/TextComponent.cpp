#include "TextComponent.h"
#include "Engine.h"

namespace Ethrl {
    void TextComponent::Update() {

    }

    void TextComponent::Draw(Renderer& renderer) {
        g_Renderer.Draw(m_Texture, m_Owner->m_Transform, Registration);
    }

    void TextComponent::SetText(const std::string& text) {
        m_Texture->CreateFromSurface(m_Font->CreateSurface(text, color), g_Renderer);
    }

    bool TextComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool TextComponent::Read(const rapidjson::Value& value) {
        READ_DATA(value, Text);
        READ_DATA(value, FontName);
        READ_DATA(value, FontSize);
        READ_DATA(value, Registration);
        READ_DATA(value, color);

        m_Font = g_Resources.Get<Font>(FontName, FontSize);
        m_Texture = std::make_unique<Texture>();

        SetText(Text);

        return true;
    }
}