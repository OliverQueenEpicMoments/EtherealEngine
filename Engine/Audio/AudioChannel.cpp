#include "AudioChannel.h"
#include <fmod.hpp>

namespace Ethrl {
    bool AudioChannel::IsPlaying() {
        if (m_Channel = nullptr) return false;

        bool isplaying;
        m_Channel->isPlaying(&isplaying);

        return isplaying;
    }

    void AudioChannel::Stop() {
        if (IsPlaying()) m_Channel->stop();
    }

    void AudioChannel::SetPitch(float pitch) {
        if (IsPlaying()) m_Channel->setPitch(pitch);
    }

    float AudioChannel::GetPitch() {
        float pitch = 0;
        if (IsPlaying()) m_Channel->getPitch(&pitch);

        return pitch;
    }

    void AudioChannel::SetVolume(float volume) {
        if (IsPlaying()) m_Channel->setVolume(volume);
    }

    float AudioChannel::GetVolume() {
        float volume = 0;
        if (IsPlaying()) m_Channel->getVolume(&volume);

        return volume;
    }
}