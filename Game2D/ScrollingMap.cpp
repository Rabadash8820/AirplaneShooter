#include "ScrollingMap.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	ScrollingMap::ScrollingMap(sf::Vector2f velocity, sf::RenderWindow* window, sf::FloatRect worldBounds, size_t numLayers) :
		Map(window, worldBounds, numLayers),
		_scrollVelocity(velocity)
	{

	}
	ScrollingMap::~ScrollingMap() {}

	// HELPER FUNCTIONS
	void ScrollingMap::baseUpdate(sf::Time dt) {
		_view.move(_scrollVelocity * dt.asSeconds());
		postScrollUpdate(dt);
	}

}