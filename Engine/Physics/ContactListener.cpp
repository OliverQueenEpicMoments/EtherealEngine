#include "ContactListener.h"
#include "FrameWork/Actor.h"
#include "Components/CollisionComponent.h"
#include <iostream>

namespace Ethrl {
	void ContactListener::BeginContact(b2Contact* Contact) {
		b2Fixture* FixtureA = Contact->GetFixtureA();
		b2Fixture* FixtureB = Contact->GetFixtureB();

		if (FixtureA->GetUserData().pointer || FixtureB->GetUserData().pointer) {
			Actor* actorA = (Actor*)(FixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(FixtureB->GetUserData().pointer);

			if (actorA->GetComponent<CollisionComponent>()) {
				actorA->GetComponent<CollisionComponent>()->OnCollisionEnter(actorB);
			}

			if (actorB->GetComponent<CollisionComponent>()) {
				actorB->GetComponent<CollisionComponent>()->OnCollisionEnter(actorA);
			}
		}
	}

	void ContactListener::EndContact(b2Contact* Contact) {
		b2Fixture* FixtureA = Contact->GetFixtureA();
		b2Fixture* FixtureB = Contact->GetFixtureB();

		if (FixtureA->GetUserData().pointer || FixtureB->GetUserData().pointer) {
			Actor* actorA = (Actor*)(FixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(FixtureB->GetUserData().pointer);

			if (actorA->GetComponent<CollisionComponent>()) {
				actorA->GetComponent<CollisionComponent>()->OnCollisionExit(actorB);
			}

			if (actorB->GetComponent<CollisionComponent>()) {
				actorB->GetComponent<CollisionComponent>()->OnCollisionExit(actorA);
			}
		}
	}
}