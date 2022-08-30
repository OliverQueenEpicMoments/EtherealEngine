#pragma once
#include "FrameWork/Component.h"
#include "Math/Rect.h"

namespace Ethrl {
	class Renderer;
	class RenderComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() { return source; }

		friend class CollisionComponent;
	protected:
		Rect source;
	};
}