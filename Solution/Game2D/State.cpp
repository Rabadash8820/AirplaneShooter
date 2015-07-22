#include "State.h"
#include "StateManager.h"

using namespace Game2D;
using namespace sf;

// CONSTRUCTOR FOR STATE CONTEXT
State::Context::Context(sf::RenderWindow& window, TextureManager& textures, FontManager& fonts) {
	this->window = &window;
	this->textures = &textures;
	this->fonts = &fonts;
}

// INTERFACE
State::State(StateManager& manager, Context context) :
	_manager(&manager),
	_context(context)
{}
State::~State() { }

// HELPER FUNCTIONS
void State::requestPush(StateId id) {
	_manager->push(id);
}
void State::requestPop() {
	_manager->pop();
}
void State::requestClear() {
	_manager->clear();
}
State::Context State::getContext() const {
	return _context;
}
void State::centerOrigin(Sprite& sprite) {
	FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(
		floor(bounds.left + bounds.width / 2.f),
		floor(bounds.top + bounds.height / 2.f));
}
void State::centerOrigin(Text& text) {
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(
		floor(bounds.left + bounds.width / 2.f),
		floor(bounds.top + bounds.height / 2.f));
}