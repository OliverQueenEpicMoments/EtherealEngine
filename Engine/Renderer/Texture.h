#pragma once
#include "Math\Vector2.h"
#include "Resource/Resource.h"
#include <string>

struct SDL_Texture;

namespace Ethrl {
	class Renderer;

	class Texture : public Resource {
	friend class Renderer;
	public:
		Texture() = default;
		~Texture ();

		bool Create(const std::string& FileName, void* Data = nullptr) override;
		bool Create(Renderer& renderer, const std::string& FileName);

		Vector2 GetSize() const;

	private:
		SDL_Texture* m_Texture = nullptr;
	};
}