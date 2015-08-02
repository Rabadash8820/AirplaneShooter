#include "PauseState.h"

#include "States.h"
#include "..\ResourceIds\Fonts.h"

#include <Utility.h>

#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>

using namespace Game2D;
using namespace Shooter;
using namespace sf;

PauseState::PauseState(Game2D::StateManager& manager, Context context) :
	State(manager, context)
{
	Font& font = (*context.fonts)[Fonts::Main];
	Vector2f viewSize = context.window->getView().getSize();

	// Define the Pause text
	_pauseText.setFont(font);
	_pauseText.setString("Game Paused");
	_pauseText.setCharacterSize(70);
	Utility::centerOrigin(_pauseText);
	_pauseText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);

	// Define the Instructions text
	_instructionText.setFont(font);
	_instructionText.setString("(Press Backspace to return to the main menu)");
	Utility::centerOrigin(_instructionText);
	_instructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
}

bool PauseState::handleEvent(const sf::Event& e) {
	if (e.type != Event::KeyPressed)
		return false;

	switch (e.key.code) {
		// Return to Previous state
	case Keyboard::Escape:
		requestPopState();
		break;

		// Return to Main Menu
	case Keyboard::BackSpace:
		requestClearStates();
		requestPushState(States::Menu);
		break;
	}

	// Don't allow other States to handle this Event
	return false;
}
bool PauseState::update(sf::Time dt) {
	// Don't allow other States to update
	return false;
}
void PauseState::draw() {
	RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	RectangleShape background;
	background.setFillColor(Color(0, 0, 0, 150));
	background.setSize(Vector2f(window.getView().getSize()));

	window.draw(background);
	window.draw(_pauseText);
	window.draw(_instructionText);
}
