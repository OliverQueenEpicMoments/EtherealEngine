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
}