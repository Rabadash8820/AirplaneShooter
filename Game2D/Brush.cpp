#include "Brush.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Brush::Brush(const sf::Texture& texture) :
		_sprite(texture)
	{

	}
	Brush::Brush(const sf::Texture& texture, const sf::IntRect& rect) :
		_sprite(texture, rect)
	{

	}

	// INTERFACE FUNCTIONS
	void Brush::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(this->_sprite, states);
	}

}