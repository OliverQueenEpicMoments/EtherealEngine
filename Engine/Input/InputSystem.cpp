#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace Ethrl {
	const uint32_t Key_Space = SDL_SCANCODE_SPACE;
	const uint32_t Key_W = SDL_SCANCODE_W;
	const uint32_t Key_S = SDL_SCANCODE_S;
	const uint32_t Key_A = SDL_SCANCODE_A;
	const uint32_t Key_D = SDL_SCANCODE_D;
	const uint32_t Key_Escape = SDL_SCANCODE_ESCAPE;

	const uint32_t Button_Left = 0;
	const uint32_t Button_Middle = 1;
	const uint32_t Button_Right = 2;

	void InputSystem::Initialize() {
		const uint8_t* KeyboardState = SDL_GetKeyboardState(&m_NumKeys);

		m_KeyboardState.resize(m_NumKeys);
		std::copy(KeyboardState, KeyboardState + m_NumKeys, m_KeyboardState.begin());

		m_PrevKeyboardState = m_KeyboardState;
	}

	void InputSystem::Shutdown() {

	}

	void InputSystem::Update() {
		SDL_Event event;
		SDL_PollEvent(&event);

		// Save previous keyboard state
		m_PrevKeyboardState = m_KeyboardState;

		// Get current keyboard state
		const uint8_t* KeyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(KeyboardState, KeyboardState + m_NumKeys, m_KeyboardState.begin());
		//std::copy(KeyboardState, KeyboardState + m_KeyboardState.size(), m_KeyboardState.begin());

		// Mouse
		m_PrevMouseButtonState = m_MouseButtonState;
		int X, Y;
		uint32_t Buttons = SDL_GetMouseState(&X, &Y);
		m_MousePosition = Ethrl::Vector2{ X, Y };

		if (GetButtonDown(Ethrl::Button_Left)) {
			//std::cout << "X: " << X << std::endl;
			//std::cout << "Y: " << Y << std::endl;
		}

		m_MouseButtonState[0] = Buttons & SDL_BUTTON_LMASK;
		m_MouseButtonState[1] = Buttons & SDL_BUTTON_MMASK;
		m_MouseButtonState[2] = Buttons & SDL_BUTTON_RMASK;
	}

	InputSystem::State InputSystem::GetKeyState(uint32_t key) {
		State KeyState = State::Idle;

		bool KeyDown = GetKeyDown(key);
		bool PrevKeyDown = GetPreviousKeyDown(key);

		if (KeyDown == true && PrevKeyDown == true) KeyState = State::Held;
		if (KeyDown == false && PrevKeyDown == false) KeyState = State::Idle;
		if (KeyDown == true && PrevKeyDown == false) KeyState = State::Pressed;
		if (KeyDown == false && PrevKeyDown == true) KeyState = State::Released;

		return KeyState;
	}

	InputSystem::State InputSystem::GetButtonState(uint32_t Button) {
		State KeyState = State::Idle;

		bool ButtonDown = GetButtonDown(Button);
		bool PrevButtonDown = GetPreviousButtonDown(Button);

		if (ButtonDown == true && PrevButtonDown == true) KeyState = State::Held;
		if (ButtonDown == false && PrevButtonDown == false) KeyState = State::Idle;
		if (ButtonDown == true && PrevButtonDown == false) KeyState = State::Pressed;
		if (ButtonDown == false && PrevButtonDown == true) KeyState = State::Released;

		return KeyState;
	}
}