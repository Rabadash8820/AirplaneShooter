#include "TitleState.h"

#include "States.h"
#include "../ResourceIds/Fonts.h"
#include "../ResourceIds/Textures.h"

#include <Utility.h>

#include <string>

using namespace Game2D;
using namespace Shooter;
using namespace sf;
using namespace std;

// INTERFACE
TitleState::TitleState(Game2D::StateManager& manager) :
	State(manager),
	_showText(true),
	_effectTime(sf::Time::Zero),
	_background(getContext().textures->get(Textures::TitleScreen)),
	_text("Press any key to start", getContext().fonts->get(Fonts::Main))
{
	// Define the flashing title Text
	Utility::centerOrigin(_text);
	_text.setPosition(getContext().window->getView().getSize() / 2.f);
}
void TitleState::draw() {
	// Draw the background Sprite and foreground Text
	sf::RenderWindow& window = *(getContext().window);
	window.draw(_background);
	if (_showText)
		window.draw(_text);
}
bool TitleState::update(sf::Time dt) {
	// Toggle the text effect
	_effectTime += dt;
	if (_effectTime >= TEXT_EFFECT_TIME) {
		_showText = !_showText;
		_effectTime = Time::Zero;
	}

	// Allow other States to update
	return true;
}
bool TitleState::handleEvent(const sf::Event& e) {
	// If the user presses (and releases) any key, move to the Menu state
	if (e.type == Event::KeyReleased) {
		requestPopState();
		requestPushState(States::MainMenu);
	}

	// Allow other States to handle this Event
	return true;
}
