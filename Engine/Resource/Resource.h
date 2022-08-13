#pragma once
#include <string>

namespace Ethrl {
	class Resource {
	public:
		virtual bool Create(const std::string& Name, void* Data = nullptr) = 0;
	};
}