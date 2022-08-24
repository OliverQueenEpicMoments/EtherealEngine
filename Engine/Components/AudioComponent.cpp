#include "AudioComponent.h"
#include "Engine.h"

namespace Ethrl {
	AudioComponent::~AudioComponent() {
		Stop();
	}

	void AudioComponent::Initialize() {
		if (PlayOnStart) {
			Play();
		}
	}

	void AudioComponent::Update() {

	}

	void AudioComponent::Play() {
		m_Channel.Stop();
		m_Channel = g_AudioSystem.PlayAudio(SoundName, Volume, Pitch, Loop);
	}

	void AudioComponent::Stop() {
		m_Channel.Stop();
	}

	bool AudioComponent::Write(const rapidjson::Value& value) const {
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value) {
		READ_DATA(value, SoundName);
		READ_DATA(value, Volume);
		READ_DATA(value, Pitch);
		READ_DATA(value, PlayOnStart);
		READ_DATA(value, Loop);

		g_AudioSystem.AddAudio(SoundName, SoundName);

		return true;
	}
}