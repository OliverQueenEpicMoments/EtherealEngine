#pragma once
#include <functional>
#include <string>
#include <variant>

namespace Ethrl {
	class GameObject;
	class Event {
	public:
		using FunctionPtr = std::function<void(const Event&)>;

	public:
		std::string Name;
		GameObject* Reciever = nullptr;
		std::variant <int, bool, float, std::string> Data;
	};
}