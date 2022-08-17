#include "AudioComponent.h"
#include "Engine.h"

namespace Ethrl {
	void AudioComponent::Update() {

	}

	void AudioComponent::Play(std::string Name, bool Loop) {
		g_AudioSystem.PlayAudio(Name, Loop);
	}

	void AudioComponent::Stop() {

	}

	bool AudioComponent::Write(const rapidjson::Value& value) const {
		return false;
	}

	bool AudioComponent::Read(const rapidjson::Value& value) {
		return false;
	}
}