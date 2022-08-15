#pragma once
#include <string>

namespace Ethrl {
	class Resource {
	public:
		virtual bool Create(std::string Name, ...) = 0;
	};
}