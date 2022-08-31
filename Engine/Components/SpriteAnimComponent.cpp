#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"
#include "Engine.h"

namespace Ethrl {
    void SpriteAnimComponent::Update() {
        frametimer += g_Time.DeltaTime;
        if (frametimer >= 1.0f / fps) {
            frametimer = 0;
            frame++;
            if (frame > end_frame) {
                frame = start_frame;
            }
        }
    }

    void SpriteAnimComponent::Draw(Renderer& renderer) {
        renderer.Draw(m_Texture, GetSource(), m_Owner->m_Transform, Registration, HorizontalFlip);
    }

    bool SpriteAnimComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool SpriteAnimComponent::Read(const rapidjson::Value& value) {
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

    Rect& SpriteAnimComponent::GetSource() {
        Vector2 CellSize = m_Texture->GetSize() / Vector2{ num_columns, num_rows };

        int Column = (frame - 1) % num_columns;
        int Row = (frame - 1) / num_columns;

        source.X = (int)(Column * CellSize.X);
        source.Y = (int)(Row * CellSize.Y);
        source.W = (int)(CellSize.X);
        source.H = (int)(CellSize.Y);

        return source;
    }
}