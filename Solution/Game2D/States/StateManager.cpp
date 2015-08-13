#include "StateManager.h"

#include <cassert>

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
StateManager::StateManager(Context* context) :
	_context(*context)
{ }
void StateManager::update(Time dt) {
	// Iterate through the State stack from top to bottom
	for (auto state = _stack.rbegin(); state != _stack.rend(); ++state) {
		bool othersCanUpdate = (*state)->update(dt);
		if (!othersCanUpdate)
			break;
	}

	applyPendingChanges();
}
void StateManager::draw() {
	// Iterate through the State stack from bottom to top
	for (auto state = _stack.begin(); state != _stack.end(); ++state)
		(*state)->draw();
}
void StateManager::handleEvent(const Event& e) {
	// Iterate through the State stack from top to bottom
	for (auto state = _stack.rbegin(); state != _stack.rend(); ++state) {
		bool othersCanHandle = (*state)->handleEvent(e);
		if (!othersCanHandle)
			break;
	}

	applyPendingChanges();
}
void StateManager::pop() {
	_pendingChanges.push_back({
		Action::Pop,
		nullptr
	});
}
void StateManager::clear() {
	_pendingChanges.push_back({
		Action::Clear,
		nullptr
	});
}
bool StateManager::isEmpty() const {
	return _stack.empty();
}
const Context& StateManager::getContext() const {
	return _context;
}

// HELPER FUNCTIONS
void StateManager::applyPendingChanges() {
	// Apply each pending change
	for (PendingChange& pc : _pendingChanges) {
		switch (pc.action) {
		case Action::Push:
			_stack.push_back(move(pc.state));
			break;

		case Action::Pop:
			_stack.pop_back();
			break;

		case Action::Clear:
			_stack.clear();
			break;
		}
	}

	// Clear the list of PendingChanges for the next frame
	_pendingChanges.clear();
}
