#include "Json.h"
#include "rapidjson/istreamwrapper.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/Rect.h"
#include "Core/Logger.h"
#include <fstream>

namespace Ethrl {
	namespace Json {
		bool Load(const std::string& FileName, rapidjson::Document& Document) {
			std::ifstream stream(FileName);
			if (stream.is_open() == false) {
				LOG("Error opening file %s.", FileName.c_str());
				return false;
			}

			rapidjson::IStreamWrapper istream(stream);
			Document.ParseStream(istream);
			if (Document.IsObject() == false) {
				LOG("JSON file cannot be read %s.", FileName.c_str());
				return false;
			}
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, int& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsInt()) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}
			Data = value[Name.c_str()].GetInt();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, float& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsNumber()) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}
			Data = value[Name.c_str()].GetFloat();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, bool& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsBool()) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}
			Data = value[Name.c_str()].GetBool();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, std::string& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsString()) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}
			Data = value[Name.c_str()].GetString();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, Vector2& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsArray() || value[Name.c_str()].Size() != 2) {
				LOG("error reading json data %s", Name.c_str());
				return false;
			}

			auto& array = value[Name.c_str()];
			for (rapidjson::SizeType I = 0; I < array.Size(); I++) {
				if (!array[I].IsNumber()) {
					LOG("error reading json data (not a float) %s", Name.c_str());
					return false;
				}
				Data[I] = array[I].GetFloat();
			}
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, Color& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsArray() || value[Name.c_str()].Size() != 4) {
				LOG("error reading json data %s", Name.c_str());
				return false;
			}

			auto& array = value[Name.c_str()];
			for (rapidjson::SizeType I = 0; I < array.Size(); I++) {
				if (!array[I].IsInt()) {
					LOG("error reading json data (not an int) %s", Name.c_str());
					return false;
				}
				Data[I] = array[I].GetFloat();
			}
			return true;
		}

		// [0, 0, 32, 32]
		bool Get(const rapidjson::Value& value, const std::string& Name, Rect& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsArray() || value[Name.c_str()].Size() != 4) {
				LOG("error reading json data %s", Name.c_str());
				return false;
			}

			auto& array = value[Name.c_str()];

			Data.X = array[0].GetInt();
			Data.Y = array[1].GetInt();
			Data.W = array[2].GetInt();
			Data.H = array[3].GetInt();

			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, std::vector<std::string>& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsArray()) {
				LOG("error reading json data %s", Name.c_str());
				return false;
			}

			auto& array = value[Name.c_str()];
			for (rapidjson::SizeType I = 0; I < array.Size(); I++) {
				if (!array[I].IsString()) {
					LOG("error reading json data (not a string) %s", Name.c_str());
					return false;
				}
				Data.push_back(array[I].GetString());
			}
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, std::vector<int>& Data) {
			if (!value.HasMember(Name.c_str())) return false;

			if (!value[Name.c_str()].IsArray()) {
				LOG("error reading json data %s", Name.c_str());
				return false;
			}

			auto& array = value[Name.c_str()];
			for (rapidjson::SizeType I = 0; I < array.Size(); I++) {
				if (!array[I].IsInt()) {
					LOG("error reading json data (not an int) %s", Name.c_str());
					return false;
				}
				Data.push_back(array[I].GetInt());
			}
			return true;
		}
	}
}