#include "State.h"

#include "StateManager.h"

using namespace Game2D;
using namespace sf;

// CONSTRUCTOR FOR STATE CONTEXT
State::Context::Context(
	sf::RenderWindow& window,
	TextureManager& textures,
	FontManager& fonts,
	InputManager& inputManager)
{
	this->window = &window;
	this->textures = &textures;
	this->fonts = &fonts;
	this->inputManager = &inputManager;
}

// INTERFACE
State::State(StateManager& manager, Context context) :
	_manager(&manager),
	_context(context)
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
State::Context State::getContext() const {
	return _context;
}
