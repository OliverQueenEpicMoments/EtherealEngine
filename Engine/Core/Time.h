#pragma once
#include <chrono>

namespace Ehtrl {
	class Time {
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;


	public:
		Time() :
			m_StartTimePoint{ clock::now() },
			m_FrameTimePoint{ clock::now() } {};
		
		void Tick();
		void Reset() { m_StartTimePoint = clock::now(); }

	public:
		float DeltaTime = 0;
		float time = 0;


	private:
		clock::time_point m_StartTimePoint; // Time point at start of app
		clock::time_point m_FrameTimePoint;

	};
}