#include "GameState.h"

using namespace sf;
using namespace std;
using namespace Shooter;
using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
GameState::GameState(StateManager& manager, Context context) :
	State(manager, context),
	_player(*reinterpret_cast<Player*>(context.player))
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
bool GameState::update(Time dt) {
	_map->update(dt);

	// Allow other States to update
	return true;
}
void GameState::draw() {
	sf::RenderWindow& window = *(getContext().window);
	window.draw(*_map);
}
