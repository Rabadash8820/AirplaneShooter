#include "PauseState.h"

using namespace Shooter;

PauseState::PauseState(Game2D::StateManager& manager, Context context) :
	State(manager, context)
{ }

bool PauseState::handleEvent(const sf::Event&) {
	// Allow other States to handle this Event
	return true;
}
bool PauseState::update(sf::Time) {
	// Allow other States to update
	return true;
}
void PauseState::draw() {

}
