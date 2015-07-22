#include "TitleState.h"

#include "States.h"
#include "../ResourceIds/Fonts.h"
#include "../ResourceIds/Textures.h"

using namespace Game2D;
using namespace Shooter;
using namespace sf;

// INTERFACE
TitleState::TitleState(Game2D::StateManager& manager, Context context) :
	State(manager, context),
	_showText(true),
	_effectTime(sf::Time::Zero),
	_text("Press any key to start", context.fonts->get(Fonts::Main))
{
	_backgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	centerOrigin(_text);
	_text.setPosition(context.window->getView().getSize() / 2.f);
}
void TitleState::draw() {
	// Draw the background Sprite and foreground Text
	sf::RenderWindow& window = *(getContext().window);
	window.draw(_backgroundSprite);
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

	return true;
}
bool TitleState::handleEvent(const sf::Event& e) {
	// If the user presses any key, move to the Menu state
	if (e.type == Event::KeyPressed) {
		requestPop();
		requestPush(States::Menu);
	}

	return true;
}
