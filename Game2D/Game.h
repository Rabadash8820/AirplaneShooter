#pragma once

#include "GAME2D_API.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace Game2D {

	class GAME2D_API Game {
		// TYPES
	public:
		typedef std::unique_ptr<Map> MapPtr;

		// VARIABLES / CONSTANTS
	protected:
		sf::Time _frameDuration;
		sf::RenderWindow _window;
		std::unique_ptr<Map> _map;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Game(sf::Time, sf::VideoMode, std::string);
		~Game();

		// INTERFACE FUNCTIONS
	public:
		void run();

		// HELPER FUNCTIONS
	protected:
		void setMap(MapPtr);
	private:
		void processEvents(sf::Time);
		void update();
		void draw();

	};

}