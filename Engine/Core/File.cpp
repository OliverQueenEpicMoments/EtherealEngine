#include "File.h"
#include "Logger.h"
#include <filesystem>
#include <fstream>

namespace Ethrl {
	void Ethrl::SetFilePath(const std::string& PathName) {
		std::filesystem::current_path(PathName);
	}
	std::string GetFilePath() {
		return std::filesystem::current_path().string();
	}
	bool FileExists(const std::string& PathName) {
		return std::filesystem::exists(PathName);
	}

	bool GetFileSize(const std::string& PathName, size_t& Size) {
		if (!FileExists(PathName)) return false;

		Size = std::filesystem::file_size(PathName);

		return true;
	}

	bool ReadFile(const std::string& PathName, std::string& Buffer) {
		if (!FileExists(PathName)) {
			LOG("Error could not read file %s", PathName.c_str());

			return false;
		}

		// Get file and set buffer
		size_t size;
		GetFileSize(PathName, size);
		Buffer.resize(size);

		// Read file into buffer
		std::ifstream Fstream(PathName);
		Fstream.read(Buffer.data(), size);
		Fstream.close();

		return true;
	}
}