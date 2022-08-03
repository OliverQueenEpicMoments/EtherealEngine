#pragma once

#ifdef _DEBUG
	#define LOG(Format, ...) Ethrl::g_Logger.Log(Format, __VA_ARGS__)
#else
	#define LOG(Format, ...) ((void)0) 
#endif // _DEBUG


namespace Ethrl {
	class Logger {
	public:
		Logger() = default;
		~Logger() = default;

		void Log(const char* Format, ...);

	private:

	};

	extern Logger g_Logger;
}