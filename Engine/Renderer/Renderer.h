#pragma once
#include "../Math/Color.h"
#include "../Math/Vector2.h"
#include "Texture.h"

struct SDL_Renderer;
struct SDL_Window;

namespace Ethrl {
	struct Transform; // Struct or Class
	class Renderer {
		friend class Text;
		friend class Texture;
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutdown();

		void CreateWindow(const char* Name, int Width, int Height);
		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color& color) { m_ClearColor = color; }

		void Draw(std::shared_ptr<Texture> texture, const Vector2& position, float Angle = 0, const Vector2& Scale = Vector2{ 1, 1 }, const Vector2& Registration = Vector2{.5f, .5f});
		void Draw(std::shared_ptr<Texture> texture, const Transform& transform, const Vector2& Registration = Vector2{ .5f, .5f });

		void DrawLine(float X1, float Y1, float X2, float Y2);
		void DrawLine(const Vector2& V1, const Vector2& V2, const Color& color);
		void DrawPoint(float X, float Y);
		void DrawPoint(const Vector2& V, const Color& color);

		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }

	private:
		int m_Width = 0;
		int m_Height = 0;
		Color m_ClearColor{0, 0, 0, 255};

		SDL_Renderer* m_renderer{ nullptr };
		SDL_Window* m_window{ nullptr };
	};
}