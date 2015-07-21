#pragma once

#include "../GAME2D_API.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

namespace Game2D {

	class GAME2D_API ScrollingMap : public Map {
		// VARIABLES
	protected:
		sf::Vector2f _scrollVelocity;	// Pixels per sec

		// CONSTRUCTORS / DESTRUCTOR
	public:
		ScrollingMap(sf::Vector2f, sf::RenderWindow*, sf::FloatRect, size_t);
		~ScrollingMap();

		// HELPER FUNCTIONS
	protected:
		virtual void buildScene();
		virtual void updateCurrent(sf::Time);

	};

}
