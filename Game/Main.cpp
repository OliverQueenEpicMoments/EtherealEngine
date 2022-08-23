#include "Engine.h"
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
	{
		// Create Scene
 		Ethrl::Scene scene;

		rapidjson::Document document;
		bool success = Ethrl::Json::Load("Level.txt", document);

		scene.Read(document);
		scene.Initialize();

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
			scene.Update();

			// Render
			Ethrl::g_Renderer.BeginFrame();

			scene.Draw(Ethrl::g_Renderer); 

			Ethrl::g_Renderer.EndFrame();
		}
		Ethrl::g_PhysicsSystem.Shutdown();
		Ethrl::g_AudioSystem.Shutdown();
		Ethrl::g_Renderer.Shutdown();
	}
}