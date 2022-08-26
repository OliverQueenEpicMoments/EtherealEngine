#pragma once
#include "rapidjson/document.h"
#include <vector>
#include <string>

#define READ_DATA(value, data) Ethrl::Json::Get(value, #data, data)

namespace Ethrl {
	struct Vector2;
	struct Color;
	struct Rect;
	namespace Json {
		bool Load(const std::string& filename, rapidjson::Document& document);

		bool Get(const rapidjson::Value& value, const std::string& Name, int& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, float& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, bool& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, std::string& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, Vector2& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, Color& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, Rect& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, std::vector<std::string>& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, std::vector<int>& Data);
	}
}