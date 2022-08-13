#pragma once
#include "Resource.h"
#include <map>
#include <string>
#include <memory>

namespace Ethrl {
	class ResourceManager {
	public:
		ResourceManager() = default;
		~ResourceManager() = default;

		void Initialize();
		void Shutdown();

		template <typename T>
		std::shared_ptr<T> Get(const std::string& Name, void* Data = nullptr);

	private:
		std::map<std::string, std::shared_ptr<Resource>> m_Resources;

	};

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::Get(const std::string& Name, void* Data) {
		if (m_Resources.find(Name) != m_Resources.end()) {
			// Found
			return std::dynamic_pointer_cast<T>(m_Resources[Name]);
		} else {
			// Not found
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(Name, Data);
			m_Resources[Name] = resource;

			return resource;
		}
	}
}