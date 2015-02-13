#include "Map.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Map::Map(sf::RenderWindow& w, size_t layers) :
		_window(w),
		_view(_window.getDefaultView()),
		_player(nullptr)
	{
		// Override world-initialization processes
		loadResources();
		buildScene();

		// Set the window's View
		_window.setView(_view);

		// Add each scene layer to the scene graph and layer array
		for (size_t L = 0; L < layers; ++L) {
			Game2D::SceneNode::Ptr layer(new Game2D::SceneNode());
			_sceneLayers.push_back(layer.get());
			_sceneGraph.attachChild(std::move(layer));
		}
	}
	Map::~Map() {}

	// INTERFACE FUNCTIONS
	void Map::update(sf::Time dt) {
		baseUpdates(dt);
		_sceneGraph.update(dt);
	}
	void Map::render() {
		_window.draw(_sceneGraph);
	}

}