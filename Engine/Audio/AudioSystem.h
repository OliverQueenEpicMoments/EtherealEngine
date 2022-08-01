#pragma once
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
		void PlayAudio(const std::string& Name, bool Loop = false);

	private:
		FMOD::System* m_FModSystem;
		std::map<std::string, FMOD::Sound*> m_Sounds;
	};
}