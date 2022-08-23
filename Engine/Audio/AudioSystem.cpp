#include "AudioSystem.h"
#include "Core/Logger.h"
#include <fmod.hpp>

namespace Ethrl {
	void AudioSystem::Initialize() {
		FMOD::System_Create(&m_FModSystem);

		void* ExtraDriverData = nullptr;
		m_FModSystem->init(32, FMOD_INIT_NORMAL, ExtraDriverData);
	}

	void AudioSystem::Shutdown() {
		for (auto& sound : m_Sounds) {
			sound.second->release();
		}

		m_Sounds.clear();
		m_FModSystem->close();
		m_FModSystem->release();
	}

	void AudioSystem::Update() {
		m_FModSystem->update();
	}

	void AudioSystem::AddAudio(const std::string& Name, const std::string& FileName) {
		if (m_Sounds.find(Name) == m_Sounds.end()) {
			FMOD::Sound* sound = nullptr;
			m_FModSystem->createSound(FileName.c_str(), FMOD_DEFAULT, 0, &sound);

			if (sound == nullptr) {
				LOG("Error creating sound %s.", FileName.c_str());
			}

			m_Sounds[Name] = sound;
		}
	}

	AudioChannel AudioSystem::PlayAudio(const std::string& Name, float Volume, float Pitch, bool Loop) {
		auto Iter = m_Sounds.find(Name);
		if (Iter == m_Sounds.end()) {
			LOG("Error could not find sound %s.", Name.c_str());
			return AudioChannel{};
		}

		FMOD::Sound* sound = Iter->second;
		FMOD_MODE mode = (Loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		sound->setMode(mode);

		FMOD::Channel* Channel;
		m_FModSystem->playSound(sound, 0, false, &Channel);
		Channel->setVolume(Volume);
		Channel->setPitch(Pitch);
		Channel->setPaused(false);

		return AudioChannel{ Channel };
	}
}