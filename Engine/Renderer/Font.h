#pragma once
#include <string>

struct _TTF_Font;

namespace Ethrl {
	class Font {

	public:
		Font() = default;
		Font(const std::string& FileName, int FontSize);
		~Font();

		void Load(const std::string& FileName, int FontSize);

		friend class Text;

	private:
		_TTF_Font* m_tffFont = nullptr;
	};
}