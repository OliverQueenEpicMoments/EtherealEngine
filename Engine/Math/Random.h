#pragma once
#include <random>

namespace Ethrl {
	inline void SeedRandom(int Seed) { srand(Seed); }

	inline int Random() { return rand(); }
	inline int Random(int Max) { return Random() % Max; } // Exclusive
	inline int Random(int Min, int Max) { return Min + Random() % ((Max - Min) + 1); } // Inclusive

	inline float RandomF() { return rand() / (float)RAND_MAX; }
	inline float RandomF(float Max) { return RandomF() * Max; }
	inline float RandomF(float Min, float Max) { return Min + RandomF(Max - Min); }
}