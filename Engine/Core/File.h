#pragma once
#include <string>

namespace Ethrl {
	void SetFilePath(const std::string& PathName);
	std::string GetFilePath();

	bool FileExists(const std::string& PathName);
	bool GetFileSize(const std::string& PathName, size_t& Size);
	bool ReadFile(const std::string& PathName, std::string& Buffer);
}