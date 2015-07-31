#include "GameState.h"

#include "..\DesertMap.h"

using namespace sf;
using namespace std;
using namespace Shooter;
using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
GameState::GameState(StateManager& manager, Context context) :
	State(manager, context),
	_map(new DesertMap(context.window)),
	_player(*reinterpret_cast<Player*>(context.inputManager))
{
	_map->build();
}

// INTERFACE
bool GameState::handleEvent(const Event& e) {
	_player.handleEvent(e, _map->getCommandQueue());

	// Allow other States to handle this Event
	return true;
}
bool GameState::update(Time dt) {
	_map->update(dt);
	_player.handleRealtimeInput(_map->getCommandQueue());

	// Allow other States to update
	return true;
}
void GameState::draw() {
	sf::RenderWindow& window = *(getContext().window);
	window.draw(*_map);
}
