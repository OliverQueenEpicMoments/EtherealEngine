#pragma once
#include "rapidjson/document.h"
#include <string>

namespace Ethrl {
	namespace Json {
		bool Load(const std::string& FileName, rapidjson::Document& Document);
		bool Get(const rapidjson::Value& value, const std::string& Name, int& Data);
	}
}