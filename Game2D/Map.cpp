#include "Map.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Map::Map(sf::View view, sf::FloatRect worldBounds, size_t numLayers) :
		_view(view),
		_worldBounds(worldBounds),
		_numLayers(numLayers)
	{
		this->initialize();
	}
	Map::~Map() {}

	// INTERFACE FUNCTIONS
	void Map::update(sf::Time dt) {
		baseUpdate(dt);
		_sceneTree.update(dt);
	}
	void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		_sceneTree.draw(target, states);
	}

	// HELPER FUNCTIONS
	void Map::initialize() {
		// Add each scene layer to the scene graph and layer array
		for (size_t L = 0; L < _numLayers; ++L) {
			Game2D::SceneNode::NodePtr layer(new Game2D::SceneNode());
			_sceneLayers.push_back(layer.get());
			_sceneTree.attachChild(std::move(layer));
		}

		// Override world-initialization processes
		loadResources();
		buildScene();
	}

}