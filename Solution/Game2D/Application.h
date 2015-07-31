#pragma once

#include "GAME2D_API.h"
#include "Render\ResourceManager.h"
#include "States\StateManager.h"
#include "Input\InputManager.h"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include <string>
#include <memory>

namespace Game2D {

	class GAME2D_API Application {
		// PRIVATE VARIABLES / CONSTANTS		
	protected:
		sf::Time _frameDuration;
		sf::RenderWindow _window;
		TextureManager _textures;
		FontManager	_fonts;
		std::unique_ptr<InputManager> _inputManager;
		StateManager _stateManager;
		sf::Text _statisticsText;
		sf::Time _statisticsUpdateTime;
		std::size_t _statisticsNumFrames;

		// INTERFACE
	public:
		Application(sf::VideoMode, std::string, std::unique_ptr<InputManager>, sf::Time = sf::seconds(1.f / 60.f));
		void run();

		// HELPER FUNCTIONS
	protected:
		void processInput();
		void update(sf::Time);
		void draw();
		void updateStatistics(sf::Time);
		virtual void registerStates() = 0;
	};

}
