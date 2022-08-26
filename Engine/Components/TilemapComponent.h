#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"
#include "Math/Vector2.h"
#include <vector>

namespace Ethrl {
	class TilemapComponent : public Component {
	public:
		CLASS_DECLARATION(TilemapComponent)

		virtual void Initialize() override;
		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;


	private:
		int ColumnNum = 0;
		int RowNum = 0;
		Vector2 Size;

		std::vector<std::string> TileNames;
		std::vector<int> Tiles;
	};
}
