#include "TilemapComponent.h"
#include "Engine.h"

namespace  Ethrl {
    void TilemapComponent::Initialize() {
        for (int i = 0; i < Tiles.size(); i++) {
            int index = Tiles[i];
            if (index == 0) continue;

            auto actor = Factory::Instance().Create<Actor>(TileNames[index]);
            if (actor) {
                int x = i % ColumnNum;
                int y = i / ColumnNum;

                actor->m_Transform.Position = m_Owner->m_Transform.Position + (Vector2{ x, y } * Size);
                m_Owner->GetScene()->Add(std::move(actor));
            }
        }
    }

    void TilemapComponent::Update() {

    }

    bool TilemapComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool TilemapComponent::Read(const rapidjson::Value& value) {
        READ_DATA(value, ColumnNum);
        READ_DATA(value, RowNum);
        READ_DATA(value, Size);
        READ_DATA(value, TileNames);
        READ_DATA(value, Tiles);

        return true;
    }
}