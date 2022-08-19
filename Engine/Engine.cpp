#include "Engine.h"

namespace Ethrl {
	InputSystem g_InputSystem;
	Ehtrl::Time g_Time;
	Renderer g_Renderer;
	AudioSystem g_AudioSystem;
	ResourceManager g_Resources;
	PhysicsSystem g_PhysicsSystem;

	void Engine::Register() {
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
	}
}