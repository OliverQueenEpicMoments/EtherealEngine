#include "Actor.h"

namespace Ethrl {
	void Actor::Draw(Renderer& renderer) {
		m_Model.Draw(renderer, m_Transform.Position, m_Transform.Rotation, m_Transform.Scale);
	}
}