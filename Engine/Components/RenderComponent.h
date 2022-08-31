#pragma once
#include "FrameWork/Component.h"
#include "Math/Rect.h"
#include "Math/Vector2.h"

namespace Ethrl {
	class Renderer;
	class RenderComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() { return source; }
		void SetHorizontalFlip(bool Flip = true) { HorizontalFlip = Flip; }
		bool GetHorizontalFlip() { return HorizontalFlip; }

	protected:
		Rect source;
		Vector2 Registration = Vector2{ 0.5f, 0.5f };
		bool HorizontalFlip = false;
	};
}