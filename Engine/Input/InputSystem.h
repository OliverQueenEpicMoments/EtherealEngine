#pragma once
#include <cstdint>
#include <vector>
#include <array>
#include "../Math/Vector2.h"

namespace Ethrl {
	class InputSystem {
	public:
		enum State {
			Idle,
			Pressed,
			Held,
			Released
		};

	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		State GetKeyState(uint32_t key);
		bool GetKeyDown(int Key) { return m_KeyboardState[Key]; }
		bool GetPreviousKeyDown(uint32_t key) { return m_PrevKeyboardState[key]; }


		const Vector2& GetMousePosition() const { return m_MousePosition; }
		State GetButtonState(uint32_t Button);
		bool GetButtonDown(uint32_t Button) { return m_MouseButtonState[Button]; }
		bool GetPreviousButtonDown(uint32_t Button) { return m_PrevMouseButtonState[Button]; }

	private:
		int m_NumKeys;

		std::vector<uint8_t> m_KeyboardState;
		std::vector<uint8_t> m_PrevKeyboardState;

		// Mouse
		Vector2 m_MousePosition;
		std::array<uint8_t, 3> m_MouseButtonState;
		std::array<uint8_t, 3> m_PrevMouseButtonState;
	};

	extern const uint32_t Key_Space;
	extern const uint32_t Key_W;
	extern const uint32_t Key_S;
	extern const uint32_t Key_A;
	extern const uint32_t Key_D;
	extern const uint32_t Key_Escape;

	extern const uint32_t Button_Left;
	extern const uint32_t Button_Middle;
	extern const uint32_t Button_Right;
}