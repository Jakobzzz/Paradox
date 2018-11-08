#pragma once

// SFML
#include <SFML/Graphics/RenderTexture.hpp>

// Paradox
#include <Editor/Docking/Dock.hpp>

namespace paradox
{
	class GameDock final : public Dock
	{
	public:
		~GameDock() = default;

		virtual void update() override;
		virtual void draw(const sf::Color& color) override;

	private:
		sf::RenderTexture m_gameWindow;
	};
}