#include "Logger.h"
#include <cstdarg>
#include <iostream>

namespace Ethrl {
	Logger g_Logger;

	void Logger::Log(const char* Format, ...) {
		va_list Args;
		va_start(Args, Format);

		char Str[1024];
		vsprintf_s(Str, 1024, Format, Args);

		std::cout << Str << std::endl;

		va_end(Args);
	}
}

