#pragma once
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;
struct SDL_Surface;
struct SDL_Color;

namespace Ethrl {
	struct Color;

	class Font : public Resource {
	public:
		Font() = default;
		Font(const std::string& FileName, int FontSize);
		~Font();

		bool Create(std::string FileName, ...) override;
		SDL_Surface* CreateSurface(const std::string& Text, const Color& color);
		bool Load(const std::string& FileName, int FontSize);

		friend class Text;

	private:
		_TTF_Font* m_tffFont = nullptr;
	};
}