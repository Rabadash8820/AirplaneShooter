#include "ScrollingMap.h"

using namespace sf;
using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
ScrollingMap::ScrollingMap(Vector2f velocity, RenderWindow* window, FloatRect worldBounds, size_t numLayers) :
	Map(window, worldBounds, numLayers),
	_scrollVelocity(velocity) {

}
ScrollingMap::~ScrollingMap() {}

// HELPER FUNCTIONS
void ScrollingMap::buildScene() { }
void ScrollingMap::updateCurrent(Time dt) {
	_view.move(_scrollVelocity * dt.asSeconds());
}
