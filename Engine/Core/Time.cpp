#include "Time.h"

namespace Ethrl {
	/*void Ehtrl::Time::Tick() {
		clock_duration Duration = clock::now() - m_StartTimePoint;
		time = Duration.count() / (float)clock_duration::period::den;

		Duration = clock::now() - m_FrameTimePoint;
		DeltaTime = Duration.count() / (float)clock_duration::period::den;

		m_FrameTimePoint = clock::now();
	}*/
}

void Ehtrl::Time::Tick() {
	clock_duration Duration = clock::now() - m_StartTimePoint;
	time = Duration.count() / (float)clock_duration::period::den;

	Duration = clock::now() - m_FrameTimePoint;
	DeltaTime = Duration.count() / (float)clock_duration::period::den;

	m_FrameTimePoint = clock::now();
}