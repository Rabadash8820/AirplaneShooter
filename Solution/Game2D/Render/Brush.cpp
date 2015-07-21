#include "Brush.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Brush::Brush(const Texture& texture) :
	_sprite(texture)
{

}
Brush::Brush(const Texture& texture, const IntRect& rect) :
	_sprite(texture, rect)
{

}

// INTERFACE FUNCTIONS
void Brush::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
