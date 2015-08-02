#include "StateManager.h"
#include <cassert>

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
StateManager::StateManager(State::Context context) :
	_context(context)
{ }
void StateManager::update(Time dt) {
	// Iterate through the State "stack" from top to bottom
	for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr) {
		bool othersCanUpdate = (*itr)->update(dt);
		if (!othersCanUpdate)
			return;
	}

	applyPendingChanges();
}
void StateManager::draw() {
	// Iterate through the State "stack" from top to bottom
	for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr)
		(*itr)->draw();
}
void StateManager::handleEvent(const Event& e) {
	// Iterate through the State "stack" from top to bottom
	for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr) {
		bool othersCanHandle = (*itr)->handleEvent(e);
		if (!othersCanHandle)
			return;
	}

	applyPendingChanges();
}
void StateManager::push(StateId id) {
	_pendingChanges.push_back({
		Push,
		id,
	});
}
void StateManager::pop() {
	_pendingChanges.push_back({
		Pop,
	});
}
void StateManager::clear() {
	_pendingChanges.push_back({
		Clear,
	});
}
bool StateManager::isEmpty() const {
	return _stack.empty();
}

// HELPER FUNCTIONS
State::Ptr StateManager::createState(StateId id) {
	// Define an instance of the State associated with this Id
	auto pos = _factories.find(id);
	assert(pos != _factories.end());
	return pos->second();
}
void StateManager::applyPendingChanges() {
	// Apply each pending change
	for (PendingChange pc : _pendingChanges) {
		switch (pc.action) {
		case Push:
			_stack.push_back(createState(pc.stateId));
			break;

		case Pop:
			_stack.pop_back();
			break;

		case Clear:
			_stack.clear();
			break;
		}
	}

	// Clear the list of PendingChanges for the next frame
	_pendingChanges.clear();
}
