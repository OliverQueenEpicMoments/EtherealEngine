#pragma once
#include "../Math/Transform.h"

namespace Ethrl {
	class GameObject {
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_Transform{ transform } {}

		virtual void Update() = 0;
 
		//Transform& GetTransform() { return m_Transform; }
		Transform m_Transform;

	protected:
	};
}