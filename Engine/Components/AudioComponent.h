#pragma once
#include "FrameWork/Component.h"
#include "FrameWork/Actor.h"

namespace Ethrl {
	class AudioComponent : public Component {
	public:
		AudioComponent() = default;
		void Update() override;

		void Play(std::string Name, bool Loop);
		void Stop();

		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

		std::string m_Sound;
		bool m_PlayOnAwake = false;
		float m_Volume = 1;
		float Pitch = 1;
		bool m_Loop = false;

	private:
		
	};
}