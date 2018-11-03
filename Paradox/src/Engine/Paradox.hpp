#pragma once

// SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace paradox
{
	class Paradox
	{
	public:
		Paradox();
		~Paradox();

		void run();

	private:
		void pollEvents();
		void update(sf::Time dt);
		void updateGUI(sf::Time dt);
		void render();

		sf::RenderWindow m_window;
		sf::RenderTexture m_sceneWindow;
		sf::RenderTexture m_gameWindow;
		std::string m_engineTitle;
	};
}