#include "GameState.h"

using namespace sf;
using namespace std;
using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
GameState::GameState(StateManager& manager, Context context) :
	State(manager, context)
{ }

// INTERFACE
bool GameState::handleEvent(const Event& e) {
	switch (e.type) {
	// Let the Map handle specific key presses
	case Event::KeyPressed:
	case Event::KeyReleased:
		_map->handleEvent(e);
		break;
	}

	// Allow other States to handle Events
	return true;
}
void GameState::handleRealtimeInput() {
	// Push keyboard events to the current Map's queue
	for (auto& binding : _keyBindings) {
		if (Keyboard::isKeyPressed(binding.key))
			_map->pushCommand(binding.getCommand());
	}
}
bool GameState::update(Time dt) {
	_map->update(dt);

	// Allow other States to update
	return true;
}
void GameState::draw() {
	sf::RenderWindow& window = *(getContext().window);
	window.draw(*_map);
}
