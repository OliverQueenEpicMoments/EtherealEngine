#include "Engine.h"
#include <iostream>

int main() {
	/*std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;*/

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


		// Muisc Loop
		Ethrl::g_AudioSystem.AddAudio("Laser", "Sounds/Laser.wav");
		Ethrl::g_AudioSystem.PlayAudio("Main Theme", true);

		// Images (kirby)
		std::shared_ptr<Ethrl::Texture> texture = std::make_shared<Ethrl::Texture>();
		texture->Create(Ethrl::g_Renderer, "Images/Kirby.png");

		// Model
		std::shared_ptr<Ethrl::Model> model = std::make_shared<Ethrl::Model>();
		model->Create("Models/Player.txt");

		// Create Actors
		Ethrl::Scene scene;

		Ethrl::Transform transform{ {400, 300}, 0, {3.0f, 3.0f} }; // Big Kirby
		std::unique_ptr<Ethrl::Actor> actor = std::make_unique<Ethrl::Actor>(transform);

		// Adding Components
		std::unique_ptr<Ethrl::PlayerComponent> pcomponent = std::make_unique<Ethrl::PlayerComponent>();
		actor->AddComponent(std::move(pcomponent));

		// Sprite
		/*std::unique_ptr<Ethrl::SpriteComponent> scomponent = std::make_unique<Ethrl::SpriteComponent>();
		scomponent->m_Texture = texture;
		actor->AddComponent(std::move(scomponent));*/

		// Model
		std::unique_ptr<Ethrl::ModelComponent> mcomponent = std::make_unique<Ethrl::ModelComponent>();
		mcomponent->m_Model = model;
		actor->AddComponent(std::move(mcomponent));

		// Audio
		std::unique_ptr<Ethrl::AudioComponent> acomponent = std::make_unique<Ethrl::AudioComponent>();
		acomponent->m_Sound = "laser";
		actor->AddComponent(std::move(acomponent));

		// Physics
		std::unique_ptr<Ethrl::PhysicsComponent> phycomponent = std::make_unique<Ethrl::PhysicsComponent>();
		actor->AddComponent(std::move(phycomponent));

		// Child Actor
		Ethrl::Transform transformC{ {15, 15}, 0, {1, 1} }; 
		std::unique_ptr<Ethrl::Actor> child = std::make_unique<Ethrl::Actor>(transformC);

		std::unique_ptr<Ethrl::ModelComponent> mcomponentC = std::make_unique<Ethrl::ModelComponent>();
		mcomponentC->m_Model = model;
		child->AddComponent(std::move(mcomponentC));
		
		actor->AddChild(std::move(child));

		// Add to Scene
		scene.Add(std::move(actor));

		float Angle = 0;

		bool Quit = false;
		while (!Quit) {
			// Update
			Ethrl::g_Time.Tick();
			Ethrl::g_InputSystem.Update();
			Ethrl::g_AudioSystem.Update();

			//std::cout << Ethrl::g_Time.time << std::endl; // Time

			// Quit
			if (Ethrl::g_InputSystem.GetKeyState(Ethrl::Key_Escape) == Ethrl::InputSystem::State::Pressed) Quit = true;

			//Game.Update();

			// Update Scene
			Angle += 360.0f * Ethrl::g_Time.DeltaTime;
			scene.Update();

			// Render
			Ethrl::g_Renderer.BeginFrame();

			scene.Draw(Ethrl::g_Renderer); // Big kirby
			//Ethrl::g_Renderer.Draw(texture, { 400, 300 }, Angle, {.15f, .15f}, {.5f, .5f}); // Spinning Kirby

			Ethrl::g_Renderer.EndFrame();
		}
	}

	Ethrl::g_AudioSystem.Shutdown();
	Ethrl::g_Renderer.Shutdown();
}