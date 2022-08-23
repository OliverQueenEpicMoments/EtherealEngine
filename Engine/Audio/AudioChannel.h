#pragma once

namespace FMOD {
	class Channel;
}

namespace Ethrl {
	class AudioChannel {
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) { channel = m_Channel; }

		bool IsPlaying();
		void Stop();

		void SetPitch(float pitch);
		float GetPitch();
		void SetVolume(float volume);
		float GetVolume();

	private:
		FMOD::Channel* m_Channel = nullptr;
	};
}