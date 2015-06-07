#include "Map.h"

using namespace sf;

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Map::Map(RenderWindow* window, FloatRect worldBounds, size_t numLayers) :
		_window(window),
		_worldBounds(worldBounds),
		_numLayers(numLayers)
	{
		// Add each scene layer to the layer collection
		for (size_t L = 0; L < _numLayers; ++L) {
			SceneNode::Ptr layer(new Game2D::SceneNode());
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

}