#include "Map.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Map::Map(sf::View view, sf::FloatRect worldBounds, size_t numLayers) :
		_view(view),
		_worldBounds(worldBounds),
		_numLayers(numLayers)
	{
		// Add each scene layer to the layer collection
		for (size_t L = 0; L < _numLayers; ++L) {
			Game2D::SceneNode::NodePtr layer(new Game2D::SceneNode());
			_sceneLayers.push_back(layer.get());
			_sceneTree.attachChild(std::move(layer));
		}
	}
	Map::~Map() {}

	// INTERFACE FUNCTIONS
	void Map::update(sf::Time dt) {
		baseUpdate(dt);
		_sceneTree.update(dt);
	}
	void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(_sceneTree, states);
	}

	// HELPER FUNCTIONS
	void Map::build() {
		loadResources();
		buildScene();
	}

}