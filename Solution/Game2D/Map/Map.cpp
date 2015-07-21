#include "Map.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Map::Map(RenderWindow* window, FloatRect worldBounds, size_t numLayers, unique_ptr<Categories> c) :
		_window(window),
		_worldBounds(worldBounds),
	_numLayers(numLayers),
	_sceneTree(std::move(c)),
	_categories(std::move(c))
	{
		// Add each scene layer to the layer collection
		for (size_t L = 0; L < _numLayers; ++L) {
		SceneNode::Ptr layer(new Game2D::SceneNode(std::move(c)));
			_sceneLayers.push_back(layer.get());
			_sceneTree.attachChild(std::move(layer));
		}
}
void Map::build() {
	loadResources();
	buildScene();
	}
void Map::update(Time dt) {
	// Give all queued commands to the Scene Tree
	while (!_commands.empty()) {
		_sceneTree.giveCommand(_commands.front(), dt);
		_commands.pop();
	}

	// INTERFACE FUNCTIONS
	void Map::pushEvent(Command c) {
		_commands.push(c);
	}
	void Map::update(Time dt) {
		// Respond to events
		while (!_commands.empty())
			_sceneTree.onCommand(_commands.pop(), dt);

		// Do "normal" updates
		updateCurrent(dt);
		_sceneTree.update(dt);
	}
	void Map::draw(RenderTarget& target, RenderStates states) const {
		target.draw(_sceneTree, states);
		_window->setView(_view);
	}
Map::~Map() {}