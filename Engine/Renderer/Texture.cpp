#include "Texture.h"
#include "Renderer.h"
#include "Core/Logger.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Ethrl {
	Texture::~Texture() {
		if (m_Texture) SDL_DestroyTexture(m_Texture);
	}

	bool Texture::Create(std::string FileName, ...) {
		va_list args;
		va_start(args, FileName);

		Renderer& renderer = va_arg(args, Renderer);

		va_end(args);

		return Create(renderer, FileName);
	}

	bool Texture::Create(Renderer& renderer, const std::string& FileName) {
		// Load Surface
		SDL_Surface* surface = IMG_Load(FileName.c_str());
		if (surface == nullptr) {
			LOG(SDL_GetError());
			return false;
		}

		// Create Texture
		m_Texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		if (m_Texture == nullptr) {
			LOG(SDL_GetError());
			SDL_FreeSurface(surface);
			return false;
		}
		SDL_FreeSurface(surface);

		return true;
	}

	Vector2 Texture::GetSize() const {
		SDL_Point point;
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &point.x, &point.y);
		//return point.x | point.y;
		return {point.x, point.y};
	}
}