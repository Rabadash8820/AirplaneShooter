#include "ScrollingMap.h"
#include "../Input/Categories.h"
#include <memory>

using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
ScrollingMap::ScrollingMap(Vector2f velocity, RenderWindow* window, FloatRect worldBounds, size_t numLayers) :
	Map(window, worldBounds, numLayers, unique_ptr<Categories>(new Categories())),
	_scrollVelocity(velocity)
{

}
ScrollingMap::~ScrollingMap() {}

// HELPER FUNCTIONS
void ScrollingMap::buildScene() { }
void ScrollingMap::updateCurrent(Time dt) {
	_view.move(_scrollVelocity * dt.asSeconds());
}