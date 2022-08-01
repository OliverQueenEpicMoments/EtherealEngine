#pragma once
#include <memory>

namespace Ethrl {

	class Renderer;
	class Scene;

	class Game {
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int GetScore() { return m_Score; }
		void AddPoints(int Points) { m_Score += Points; }

	protected:
		std::unique_ptr<Scene> m_Scene;
		int m_Score = 0;
	};
}