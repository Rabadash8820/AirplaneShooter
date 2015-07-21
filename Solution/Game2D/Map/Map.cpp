#include "Map.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Map::Map(RenderWindow* window, FloatRect worldBounds, size_t numLayers) :
	_window(window),
	_worldBounds(worldBounds),
	_numLayers(numLayers)
{
	// Add each scene layer to the layer collection
	for (size_t L = 0; L < _numLayers; ++L) {
	SceneNode::Ptr layer(new Game2D::SceneNode()) ;
		_sceneLayers.push_back(layer.get());
		_sceneTree.attachChild(std::move(layer));
	}
}
void Map::build() {
	loadResources();
	buildScene();
}
void Map::pushCommand(Command c) {
	_commands.push(c);
}
void Map::update(Time dt) {
	updateCurrent(dt);
	_sceneTree.update(dt);
}
void Map::draw(RenderTarget& target, RenderStates states) const {
	target.draw(_sceneTree, states);
	_window->setView(_view);
}

// HELPER FUNCTIONS
void Map::updateOnCommands(Time dt) {
	while (!_commands.empty()) {
		_sceneTree.onCommand(_commands.front(), dt);
		_commands.pop();
	}
}
string Map::projectDirectory() {
	char currDir[FILENAME_MAX];
	GetCurrentDir(currDir, sizeof(currDir));
	// Make some assertion here...
	return currDir;
}
void Map::handleEvent(const Event&) { }
