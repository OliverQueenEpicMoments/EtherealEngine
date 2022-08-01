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

	void Font::Load(const std::string& FileName, int FontSize) {
		m_tffFont = TTF_OpenFont(FileName.c_str(), FontSize);
	}
}