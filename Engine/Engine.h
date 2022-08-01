#pragma once
#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Math/Vector2.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "FrameWork/Actor.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSystem.h"

#include <memory>
#include <vector>

namespace Ethrl {
	extern Renderer g_Renderer;
	extern InputSystem g_InputSystem;
	extern Ehtrl::Time g_Time;
	extern AudioSystem g_AudioSystem;
}