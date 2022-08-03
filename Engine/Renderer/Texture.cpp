#include "Texture.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Ethrl {
	Texture::~Texture() {
		if (m_Texture) SDL_DestroyTexture(m_Texture);
	}

	bool Texture::Create(Renderer& renderer, const std::string& FileName) {
		// Load Surface
		SDL_Surface* surface = IMG_Load(FileName.c_str());

		// Create Texture
		//SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		m_Texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
		SDL_FreeSurface(surface);

		return true;
	}

	Vector2 Texture::GetSize() const {
		SDL_Point point;
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &point.x, &point.y);

		return point.x | point.y;
	}
}