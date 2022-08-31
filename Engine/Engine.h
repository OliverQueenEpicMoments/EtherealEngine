#pragma once

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Math/Vector2.h"

#include "Physics/PhysicsSystem.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "FrameWork/Actor.h"
#include "FrameWork/Singleton.h"
#include "FrameWork/Factory.h"
#include "FrameWork/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/CharacterComponent.h"

#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Audio/AudioSystem.h"
#include "Resource/ResourceManager.h"

#include <memory>
#include <vector>
#include <variant>

namespace Ethrl {
	extern Renderer g_Renderer;
	extern InputSystem g_InputSystem;
	extern Ehtrl::Time g_Time;
	extern AudioSystem g_AudioSystem;
	extern ResourceManager g_Resources;
	extern PhysicsSystem g_PhysicsSystem;
	extern EventManager g_EventManager;

	class Engine : public Singleton<Engine> {
	public:
		void Register();
	};
}