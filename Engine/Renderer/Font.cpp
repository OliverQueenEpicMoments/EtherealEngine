#include "Font.h"
#include <SDL_ttf.h>

namespace Ethrl {
	Font::Font(const std::string& FileName, int FontSize) {
		Load(FileName, FontSize);
	}

	Font::~Font() {
		if (m_tffFont != nullptr) TTF_CloseFont(m_tffFont);
		m_tffFont = nullptr;
	}

	bool Font::Create(std::string FileName, ...) {
		va_list args;
		va_start(args, FileName);

		int FontSize = va_arg(args, int);

		va_end(args);

		return Load(FileName, FontSize);
	}

	SDL_Surface* Font::CreateSurface(const std::string& Text, const Color& color) {
		//SDL_Color c = color

		return nullptr;
	}

	bool Font::Load(const std::string& FileName, int FontSize) {
		m_tffFont = TTF_OpenFont(FileName.c_str(), FontSize);

		return true;
	}
}