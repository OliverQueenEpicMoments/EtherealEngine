#pragma once
#include "FrameWork/Component.h"

namespace Ethrl {
	class Renderer;
	class RenderComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}