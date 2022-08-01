#pragma once
//#include <SDL.h>
#include <string>

struct SDL_Texture;

namespace Ethrl {
	class Font;
	class Renderer;
	struct Color;
	struct Vector2;

	class Text {
	public:
		Text() = default;
		Text(Font* font) : m_Font{ font } {};
		~Text();

		void Create(Renderer& Renderer, const std::string& Text, const Color& Color);
		void Draw(Renderer& Renderer, const Vector2& Position);

	private:
		Font* m_Font = nullptr;
		SDL_Texture* m_Texture = nullptr;
	};
}