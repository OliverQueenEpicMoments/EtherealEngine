#pragma once
#include "../Math/Color.h"
#include "../Math/Vector2.h"

struct SDL_Renderer;
struct SDL_Window;

namespace Ethrl {

	class Renderer {
		friend class Text;
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutdown();

		void CreateWindow(const char* Name, int Width, int Height);
		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color& color) { m_ClearColor = color; }

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