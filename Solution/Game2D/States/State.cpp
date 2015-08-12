#include "State.h"

#include "StateManager.h"

using namespace Game2D;
using namespace sf;

// INTERFACE
State::State(StateManager& manager) :
	_manager(&manager),
	_context(manager.getContext())
{ }
State::~State() { }

// HELPER FUNCTIONS
void State::requestPushState(StateId id) {
	_manager->push(id);
}
void State::requestPopState() {
	_manager->pop();
}
void State::requestClearStates() {
	_manager->clear();
}
Context State::getContext() const {
	return _context;
}
