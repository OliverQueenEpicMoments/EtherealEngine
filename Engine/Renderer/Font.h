#pragma once
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;

namespace Ethrl {
	class Font : public Resource {

	public:
		Font() = default;
		Font(const std::string& FileName, int FontSize);
		~Font();

		bool Create(std::string FileName, ...) override;
		bool Load(const std::string& FileName, int FontSize);

		friend class Text;

	private:
		_TTF_Font* m_tffFont = nullptr;
	};
}