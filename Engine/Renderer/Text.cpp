#include "Text.h"
#include "Font.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace Ethrl {
	Text::~Text() {
		if (m_Texture != nullptr) {
			SDL_DestroyTexture(m_Texture);
		}
	}

	void Text::Create(Renderer& Renderer, const std::string& Text, const Color& Color) {
		SDL_Color C{ Color.R, Color.G, Color.B, Color.A };
		SDL_Surface* Surface = TTF_RenderText_Solid(m_Font->m_tffFont, Text.c_str(), C);

		m_Texture = SDL_CreateTextureFromSurface(Renderer.m_renderer, Surface);
		SDL_FreeSurface(Surface);
	}

	void Text::Draw(Renderer& Renderer, const Vector2& Position) {
		int Width, Height;
		SDL_QueryTexture(m_Texture, nullptr, nullptr, &Width, &Height);

		SDL_Rect Rect{ (int)Position.X, (int)Position.Y, Width, Height };

		SDL_RenderCopy(Renderer.m_renderer, m_Texture, NULL, &Rect);
	}
}
