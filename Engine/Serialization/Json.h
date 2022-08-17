#pragma once
#include "rapidjson/document.h"
#include <string>

namespace Ethrl {
	struct Vector2;
	struct Color;
	namespace Json {
		bool Load(const std::string& filename, rapidjson::Document& document);

		bool Get(const rapidjson::Value& value, const std::string& Name, int& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, float& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, bool& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, std::string& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, Vector2& Data);
		bool Get(const rapidjson::Value& value, const std::string& Name, Color& Data);
	}
}