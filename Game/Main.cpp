#include "Engine.h"
#include <iostream>

int main() {
	Ethrl::InitializeMemory();
	Ethrl::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = Ethrl::Json::Load("json.txt", document);
	assert(success);

	std::string str;
	Ethrl::Json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	Ethrl::Json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	Ethrl::Json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	Ethrl::Json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	Ethrl::Json::Get(document, "float", f);
	std::cout << f << std::endl;

	Ethrl::Vector2 v2;
	Ethrl::Json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	Ethrl::Color color;
	Ethrl::Json::Get(document, "color", color);
	std::cout << color << std::endl;

	// Initialize Engine
	Ethrl::g_Renderer.Initialize();
	Ethrl::g_InputSystem.Initialize();
	Ethrl::g_AudioSystem.Initialize();
	Ethrl::g_Resources.Initialize();

	// Register
	Ethrl::Engine::Instance().Register();

	// Create Window
	Ethrl::g_Renderer.CreateWindow("Neumont", 800, 600);
	Ethrl::g_Renderer.SetClearColor(Ethrl::Color{ 100, 0, 0, 255 });

	{
		// Create Actors
 		Ethrl::Scene scene;

		bool Quit = false;
		while (!Quit) {
			// Update
			Ethrl::g_Time.Tick();
			Ethrl::g_InputSystem.Update();
			Ethrl::g_AudioSystem.Update();

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
	}
	Ethrl::g_AudioSystem.Shutdown();
	Ethrl::g_Renderer.Shutdown();
}