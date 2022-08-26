#include "Engine.h"
#include "TheGame.h"
#include <iostream>

int main() {
	Ethrl::InitializeMemory();
	Ethrl::SetFilePath("../Assets");

	// Initialize Everything
	Ethrl::g_Renderer.Initialize();
	Ethrl::g_InputSystem.Initialize();
	Ethrl::g_AudioSystem.Initialize();
	Ethrl::g_Resources.Initialize();
	Ethrl::g_PhysicsSystem.initialize();

	// Register
	Ethrl::Engine::Instance().Register();

	// Create Window
	Ethrl::g_Renderer.CreateWindow("Neumont", 800, 600);
	Ethrl::g_Renderer.SetClearColor(Ethrl::Color{ 100, 0, 0, 255 });
	
	// Create Game
	std::unique_ptr<TheGame> game = std::make_unique<TheGame>();
	game->Initialize();

	bool Quit = false;
	while (!Quit) {
		// Update
		Ethrl::g_Time.Tick();
		Ethrl::g_InputSystem.Update();
		Ethrl::g_AudioSystem.Update();
		Ethrl::g_PhysicsSystem.Update();

		//std::cout << Ethrl::g_Time.time << std::endl; // Time

		// Quit
		if (Ethrl::g_InputSystem.GetKeyState(Ethrl::Key_Escape) == Ethrl::InputSystem::State::Pressed) Quit = true;

		// Update Scene
		game->Update();

		// Render
		Ethrl::g_Renderer.BeginFrame();

		game->Draw(Ethrl::g_Renderer);

		Ethrl::g_Renderer.EndFrame();
	}

	game->Shutdown();
	game.reset();

	Ethrl::Factory::Instance().Shutdown();

	Ethrl::g_PhysicsSystem.Shutdown();
	Ethrl::g_AudioSystem.Shutdown();
	Ethrl::g_Renderer.Shutdown();	
}