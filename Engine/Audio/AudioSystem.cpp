#include "AudioSystem.h"
#include <fmod.hpp>

void Ethrl::AudioSystem::Initialize() {
	FMOD::System_Create(&m_FModSystem);

	void* ExtraDriverData = nullptr;
	m_FModSystem->init(32, FMOD_INIT_NORMAL, ExtraDriverData);
}

void Ethrl::AudioSystem::Shutdown() {
	for (auto& sound : m_Sounds) {
		sound.second->release();
	}

	m_Sounds.clear();
	m_FModSystem->close();
	m_FModSystem->release();
}

void Ethrl::AudioSystem::Update() {
	m_FModSystem->update();
}

void Ethrl::AudioSystem::AddAudio(const std::string& Name, const std::string& FileName) {
	if (m_Sounds.find(Name) == m_Sounds.end()) {
		FMOD::Sound* sound = nullptr;
		m_FModSystem->createSound(FileName.c_str(), FMOD_DEFAULT, 0, &sound);
		m_Sounds[Name] = sound;
	}
}

void Ethrl::AudioSystem::PlayAudio(const std::string& Name, bool Loop) {
	auto Iter = m_Sounds.find(Name);
	if (Iter != m_Sounds.end()) {
		FMOD::Sound* sound = Iter->second;

		if (Loop) sound->setMode(FMOD_LOOP_NORMAL);
		else sound->setMode(FMOD_LOOP_OFF);

		FMOD::Channel* Channel;
		m_FModSystem->playSound(sound, 0, false, &Channel);
	}
}
