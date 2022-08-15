#pragma once
#include "Resource.h"
#include <map>
#include <string>
#include <memory>
#include <cstdarg>

namespace Ethrl {
	class ResourceManager {
	public:
		ResourceManager() = default;
		~ResourceManager() = default;

		void Initialize();
		void Shutdown();

		template <typename T, typename ... TArgs>
		std::shared_ptr<T> Get(const std::string& Name, TArgs ... args);

	private:
		std::map<std::string, std::shared_ptr<Resource>> m_Resources;

	};

	template<typename T, typename ... TArgs>
	inline std::shared_ptr<T> ResourceManager::Get(const std::string& Name, TArgs ... args) {
		if (m_Resources.find(Name) != m_Resources.end()) {
			// Found
			return std::dynamic_pointer_cast<T>(m_Resources[Name]);
		} else {
			// Not found
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(Name, args...);
			m_Resources[Name] = resource;

			return resource;
		}
	}
}