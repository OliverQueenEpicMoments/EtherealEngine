#include "Json.h"
#include "rapidjson/istreamwrapper.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
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
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsInt() == false) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}

			Data = value[Name.c_str()].GetInt();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, float& Data) {
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsNumber() == false) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}

			Data = value[Name.c_str()].GetFloat();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, bool& Data) {
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsBool() == false) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}

			Data = value[Name.c_str()].GetBool();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, std::string& Data) {
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsString() == false) {
				LOG("Error reading json data %s", Name.c_str());
				return false;
			}

			Data = value[Name.c_str()].GetString();
			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& Name, Vector2& Data) {
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsArray() == false || value[Name.c_str()].Size() != 2) {
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
			if (value.HasMember(Name.c_str()) == false || value[Name.c_str()].IsArray() == false || value[Name.c_str()].Size() != 4) {
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
	}
}