#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"
#include "Engine.h"

void Ethrl::SpriteAnimComponent::Update() {
    frametimer += g_Time.DeltaTime;
    if (frametimer >= 1.0f / fps) {
        frametimer = 0;
        frame++;
        if (frame > end_frame) {
            frame = start_frame;
        }
    }

    Vector2 cellSize = m_Texture->GetSize() / Vector2{ num_columns, num_rows };

    int column = (frame - 1) % num_columns;
    int row = (frame - 1) / num_columns;

    source.X = (int)(column * cellSize.X);
    source.Y = (int)(row * cellSize.Y);
    source.W = (int)(cellSize.X);
    source.H = (int)(cellSize.Y);
}

void Ethrl::SpriteAnimComponent::Draw(Renderer& renderer) {
    renderer.Draw(m_Texture, source, m_Owner->m_Transform);
}

bool Ethrl::SpriteAnimComponent::Write(const rapidjson::Value& value) const {
    return true;
}

bool Ethrl::SpriteAnimComponent::Read(const rapidjson::Value& value) {
    std::string SpriteName;
    READ_DATA(value, SpriteName);

    m_Texture = g_Resources.Get<Texture>(SpriteName, g_Renderer);

    READ_DATA(value, fps);
    READ_DATA(value, num_columns);
    READ_DATA(value, num_rows);
    READ_DATA(value, start_frame);
    READ_DATA(value, end_frame);

    return true;
}
