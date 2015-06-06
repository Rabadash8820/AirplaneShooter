#pragma once

#include "GAME2D_API.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace Game2D {

	class GAME2D_API Game {
		// VARIABLES / CONSTANTS
	private:
		sf::Time _frameDuration;
		bool _paused;
	protected:
		sf::RenderWindow _window;
		Map::Ptr _map;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Game(sf::VideoMode, std::string, sf::Time = sf::seconds(1.f / 60.f));
		~Game();

		// INTERFACE FUNCTIONS
	public:
		void run();

		// HELPER FUNCTIONS
	protected:
		void setMap(Map::Ptr);
	private:
		void processEvents();
		void update(sf::Time);
		void draw();

	};

}