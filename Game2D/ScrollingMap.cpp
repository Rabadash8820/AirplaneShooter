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
	void ScrollingMap::buildScene() {
		_player->Velocity = this->_scrollVelocity;
	}
	void ScrollingMap::updateCurrent(sf::Time dt) {
		_player->Velocity += _scrollVelocity;
		_view.move(_scrollVelocity * dt.asSeconds());
	}

}