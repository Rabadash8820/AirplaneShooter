#include "Map.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Map::Map(RenderWindow* window, FloatRect worldBounds, size_t numLayers, unique_ptr<Categories> c) :
	_window(window),
	_worldBounds(worldBounds),
	_numLayers(numLayers),
	_sceneTree(std::move(c))
{
	// Add each scene layer to the layer collection
	for (size_t L = 0; L < _numLayers; ++L) {
		SceneNode::Ptr layer(new Game2D::SceneNode(std::move(c)));
		_sceneLayers.push_back(layer.get());
		_sceneTree.attachChild(std::move(layer));
	}
}
Map::~Map() {}

// INTERFACE FUNCTIONS
void Map::update(Time dt) {
	updateCurrent(dt);
	_sceneTree.update(dt);
}
void Map::draw(RenderTarget& target, RenderStates states) const {
	target.draw(_sceneTree, states);
	_window->setView(_view);
}

// HELPER FUNCTIONS
void Map::build() {
	loadResources();
	buildScene();
}