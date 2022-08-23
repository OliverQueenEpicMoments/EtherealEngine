#pragma once
#include "AudioChannel.h"
#include <string>
#include <map>

namespace FMOD {
	class System;
	class Sound;
}

namespace Ethrl {
	class AudioSystem {
	public:
		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		void AddAudio(const std::string& Name, const std::string& FileName);
		AudioChannel PlayAudio(const std::string& Name, float Volume = 1, float Pitch = 1, bool Loop = false);

	private:
		FMOD::System* m_FModSystem;
		std::map<std::string, FMOD::Sound*> m_Sounds;
	};
}