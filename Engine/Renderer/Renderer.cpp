#include "Renderer.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Rect.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

namespace Ethrl {
	void Renderer::Initialize() {
		SDL_Init(SDL_INIT_VIDEO);
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
		TTF_Init();
	}

	void Renderer::Shutdown() {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		IMG_Quit();
		TTF_Quit();
	}

	void Renderer::CreateWindow(const char* Name, int Width, int Height) {
		m_Width = Width;
		m_Height = Height;

		m_window = SDL_CreateWindow(Name, 100, 100, Width, Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
	void Renderer::BeginFrame() {
		SDL_SetRenderDrawColor(m_renderer,m_ClearColor.R, m_ClearColor.G, m_ClearColor.B, m_ClearColor.A);
		SDL_RenderClear(m_renderer);
	}

	void Renderer::EndFrame() {
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::Draw(std::shared_ptr<Texture> texture, const Vector2& position, float Angle, const Vector2& Scale, const Vector2& Registration) {
		Vector2 size = texture->GetSize();
		size = size * Scale;

		Vector2 Origin = size * Registration;
		Vector2 TPosition = position - (size * .5f);

		SDL_Rect dest;
		dest.x = (int)TPosition.X;
		dest.y = (int)TPosition.Y;
		dest.w = (int)size.X;
		dest.h = (int)size.Y;

		SDL_Point Center{(int)Origin.X, (int)Origin.Y};

		SDL_RenderCopyEx(m_renderer, texture->m_Texture, nullptr, &dest, Angle, &Center, SDL_FLIP_NONE);
	}

	void Renderer::Draw(std::shared_ptr<Texture> texture, const Transform& transform, const Vector2& Registration) {
		Vector2 size = texture->GetSize();
		size = size * transform.Scale;

		Vector2 Origin = size * Registration;
		Vector2 TPosition = transform.Position - (size * .5f);

		SDL_Rect dest;
		dest.x = (int)TPosition.X;
		dest.y = (int)TPosition.Y;
		dest.w = (int)size.X;
		dest.h = (int)size.Y;

		SDL_Point Center{ (int)Origin.X, (int)Origin.Y };

		SDL_RenderCopyEx(m_renderer, texture->m_Texture, nullptr, &dest, transform.Rotation, &Center, SDL_FLIP_NONE);
	}

	void Renderer::Draw(std::shared_ptr<Texture> texture, const Rect& source, const Transform& transform, const Vector2& Registration) {
		Vector2 size = Vector2{ source.W, source.H };
		size = size * transform.Scale;

		Vector2 Origin = size * Registration;
		Vector2 TPosition = transform.Position - (size * .5f);

		SDL_Rect dest;
		dest.x = (int)TPosition.X;
		dest.y = (int)TPosition.Y;
		dest.w = (int)size.X;
		dest.h = (int)size.Y;

		SDL_Rect src;
		src.x = source.X;
		src.y = source.Y;
		src.w = source.W;
		src.h = source.H;

		SDL_Point Center{ (int)Origin.X, (int)Origin.Y };

		SDL_RenderCopyEx(m_renderer, texture->m_Texture, &src, &dest, transform.Rotation, &Center, SDL_FLIP_NONE);
	}

	void Renderer::DrawLine(float X1, float Y1, float X2, float Y2) {
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawLineF(m_renderer, X1, Y1, X2, Y2);
	}

	void Renderer::DrawLine(const Vector2& V1, const Vector2& V2, const Color& color) {
		SDL_SetRenderDrawColor(m_renderer, color.R, color.G, color.B, color.A);
		SDL_RenderDrawLineF(m_renderer, V1.X, V1.Y, V2.X, V2.Y);
	}

	void Renderer::DrawPoint(float X, float Y) {
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawPointF(m_renderer, X, Y);
	}

	void Renderer::DrawPoint(const Vector2& V, const Color& color) {
		SDL_SetRenderDrawColor(m_renderer, color.R, color.G, color.B, color.A);
		SDL_RenderDrawPointF(m_renderer, V.X, V.Y);
	}
}