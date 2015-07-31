#include "GameState.h"

using namespace sf;
using namespace std;
using namespace Shooter;
using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
GameState::GameState(StateManager& manager, Context context, Map::Ptr map) :
	State(manager, context),
	_map(std::move(map)),
	_player(*reinterpret_cast<Player*>(context.player))
{ }

// INTERFACE
bool GameState::handleEvent(const Event& e) {
	_player.handleEvent(e, _map->getCommandQueue());

	// Allow other States to handle Events
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
