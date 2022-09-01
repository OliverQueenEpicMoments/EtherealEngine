#include "SpriteAnimComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"
#include "Engine.h"

namespace Ethrl {
    void SpriteAnimComponent::Update() {
        frametimer += g_Time.DeltaTime;
        if (frametimer >= 1.0f / m_sequence->fps) {
            frametimer = 0;
            frame++;
            if (frame > m_sequence->end_frame) {
                frame = (m_sequence->loop) ? m_sequence->start_frame : m_sequence->end_frame;
            }
        }
    }

    void SpriteAnimComponent::Draw(Renderer& renderer) {
        renderer.Draw(m_sequence->Texture, GetSource(), m_Owner->m_Transform, Registration, HorizontalFlip);
    }

    void SpriteAnimComponent::SetSequence(const std::string& name) {
        if (m_sequence && m_sequence->Name == name) return;

        if (m_Sequences.find(name) != m_Sequences.end()) {
            m_sequence = &m_Sequences[name];

            frame = m_sequence->start_frame;
            frametimer = 0;
        }
    }

    Rect& SpriteAnimComponent::GetSource() {
        Vector2 CellSize = m_sequence->Texture->GetSize() / Vector2{ m_sequence->num_columns, m_sequence->num_rows };

        int Column = (frame - 1) % m_sequence->num_columns;
        int Row = (frame - 1) / m_sequence->num_columns;

        source.X = (int)(Column * CellSize.X);
        source.Y = (int)(Row * CellSize.Y);
        source.W = (int)(CellSize.X);
        source.H = (int)(CellSize.Y);

        return source;
    }

    bool SpriteAnimComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool SpriteAnimComponent::Read(const rapidjson::Value& value) {
        if (value.HasMember("sequences") && value["sequences"].IsArray()) {
            for (auto& SequenceValue : value["sequences"].GetArray()) {
                Sequence sequence;

                READ_DATA(SequenceValue, sequence.Name);
                READ_DATA(SequenceValue, sequence.fps);
                READ_DATA(SequenceValue, sequence.num_columns);
                READ_DATA(SequenceValue, sequence.num_rows);
                READ_DATA(SequenceValue, sequence.start_frame);
                READ_DATA(SequenceValue, sequence.end_frame);
                
                std::string TextureName;
                READ_DATA(SequenceValue, TextureName);

                sequence.Texture = g_Resources.Get<Texture>(TextureName, g_Renderer);

                m_Sequences[sequence.Name] = sequence;
            }
        }

        std::string DefaultSequence;
        if (!READ_DATA(value, DefaultSequence)) {
            DefaultSequence = m_Sequences.begin()->first;
        }

        SetSequence(DefaultSequence);

        return true;
    }
}