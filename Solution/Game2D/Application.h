#pragma once

#include "Render\ResourceManager.h"
#include "StateManager.h"
#include <SFML\Graphics.hpp>
#include <string>

namespace Game2D {

	class Application {
		// PRIVATE VARIABLES / CONSTANTS		
	private:
		sf::Time _frameDuration;
		sf::RenderWindow _window;
		TextureManager _textures;
		FontManager	_fonts;
		StateManager _stateManager;
		sf::Text _statisticsText;
		sf::Time _statisticsUpdateTime;
		std::size_t _statisticsNumFrames;

		// INTERFACE
	public:
		Application(sf::VideoMode, std::string, sf::Time = sf::seconds(1.f / 60.f));
		void run();

		// HELPER FUNCTIONS
	private:
		void processInput();
		void update(sf::Time);
		void draw();
		void updateStatistics(sf::Time);
		virtual void registerStates() = 0;
	};

}
