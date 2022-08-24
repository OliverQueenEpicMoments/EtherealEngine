#pragma once
#include "box2d/box2d.h"

namespace Ethrl {
	class ContactListener : public b2ContactListener {
	public:
		void BeginContact(b2Contact* Contact) override;
		void EndContact(b2Contact* Contact) override;
	};
}