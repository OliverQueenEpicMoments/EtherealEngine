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

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "FrameWork/Actor.h"
#include "FrameWork/Singleton.h"
#include "FrameWork/Factory.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"

#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSystem.h"
#include "Resource/ResourceManager.h"

#include <memory>
#include <vector>

namespace Ethrl {
	extern Renderer g_Renderer;
	extern InputSystem g_InputSystem;
	extern Ehtrl::Time g_Time;
	extern AudioSystem g_AudioSystem;
	extern ResourceManager g_Resources;

	class Engine : public Singleton<Engine> {
	public:
		void Register();

	};
}