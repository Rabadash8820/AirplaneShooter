#pragma once

#include "GAME2D_API.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Game2D {

	class GAME2D_API Game {
	private:
		// VARIABLES / CONSTANTS
		const sf::Time FRAME_DURATION = sf::seconds(1.f / 60.f);
		sf::RenderWindow _window;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		Game(std::string);
		~Game();

		// FUNCTIONS
		void run();

	private:
		void processEvents(sf::Time);
		void update();
		void render();

	};

}