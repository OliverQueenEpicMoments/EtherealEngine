#include "Engine.h"
#include <iostream>

int main() {
	Ethrl::InitializeMemory();
	Ethrl::SetFilePath("../Assets");

	// Initialize Engine
	Ethrl::g_Renderer.Initialize();
	Ethrl::g_InputSystem.Initialize();
	Ethrl::g_AudioSystem.Initialize();

	// Create Window
	Ethrl::g_Renderer.CreateWindow("Neumont", 800, 600);
	Ethrl::g_Renderer.SetClearColor(Ethrl::Color{ 100, 0, 0, 255 });

	{
		// Create Game
		//SpaceShooter Game;
		//Game.Initialize();

		Ethrl::g_AudioSystem.PlayAudio("Main Theme", true);

		bool Quit = false;
		while (!Quit) {
			// Update
			Ethrl::g_Time.Tick();
			Ethrl::g_InputSystem.Update();
			Ethrl::g_AudioSystem.Update();

			std::cout << Ethrl::g_Time.time << std::endl; // Time

			if (Ethrl::g_InputSystem.GetKeyState(Ethrl::Key_Escape) == Ethrl::InputSystem::State::Pressed) Quit = true;

			//Game.Update();

			// Render
			Ethrl::g_Renderer.BeginFrame();
			//Game.Draw(Ethrl::g_Renderer);
			Ethrl::g_Renderer.EndFrame();
		}

		int I = getchar();
	}
	/*delete Font;
	font->~Font();
	title.~Text();*/
	Ethrl::g_AudioSystem.Shutdown();
	Ethrl::g_Renderer.Shutdown();
}