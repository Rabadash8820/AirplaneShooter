#include "Map.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Map::Map(RenderWindow& window) :
	_window(window)
{ }
void Map::build() {
	loadResources();
	buildScene();
}
queue<Command>& Map::getCommandQueue() {
	return _commands;
}
void Map::update(Time dt) {
	updateCurrent(dt);
	_sceneTree.update(dt);
}
void Map::draw(RenderTarget& target, RenderStates states) const {
	drawCurrent(target, states);
	target.draw(_sceneTree, states);
}

// HELPER FUNCTIONS
void Map::updateOnCommands(Time dt) {
	while (!_commands.empty()) {
		_sceneTree.onCommand(_commands.front(), dt);
		_commands.pop();
	}
}
