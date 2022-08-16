#include "Json.h"
#include "rapidjson/istreamwrapper.h"
#include <Core/Logger.h>
#include <fstream>

namespace Ethrl {
	namespace Json {
		bool Load(const std::string& FileName, rapidjson::Document& Document) {
			std::ifstream stream;
			if (!stream.is_open()) {
				LOG("JSON file was not oppened I think %s.", FileName.c_str());
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
	}
}