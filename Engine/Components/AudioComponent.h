#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"
#include "Audio/AudioChannel.h"

namespace Ethrl {
	class AudioComponent : public Component {
	public:
		AudioComponent() = default;
		~AudioComponent();

		void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		AudioChannel m_Channel;

		std::string SoundName;
		float Volume = 1;
		float Pitch = 1;
		bool PlayOnStart = false;
		bool Loop = false;		
	};
}