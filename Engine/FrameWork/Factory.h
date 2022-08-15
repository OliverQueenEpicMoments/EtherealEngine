#pragma once
#include "Singleton.h"
#include <memory>
#include <map>
#include <string>

namespace Ethrl {
	class GameObject;
	class CreatorBase {
	public:
		virtual std::unique_ptr<GameObject> Create() = 0;
	};

	template <typename T>
	class Creator : public CreatorBase {
		std::unique_ptr<GameObject> Create() override {
			return std::make_unique<T>();
		}
	};

	class Factory : public Singleton<Factory> {
	public:
		template <typename T>
		void Register(const std::string& Key);

		template <typename T>
		std::unique_ptr<T> Create(const std::string& Key);
	private:
		std::map<std::string, std::unique_ptr<CreatorBase>> m_Registry;
	};

	template<typename T>
	inline void Factory::Register(const std::string& Key) {
		m_Registry[Key] = std::make_unique<Creator<T>>();
	}

	template<typename T>
	inline std::unique_ptr<T> Factory::Create(const std::string& Key) {
		auto Iter = m_Registry.find(Key);
		if (Iter != m_Registry.end()) {
			return std::unique_ptr<T>(dynamic_cast<T*>(Iter->second->Create().release()));
		}

		return std::unique_ptr<T>();
	}
}