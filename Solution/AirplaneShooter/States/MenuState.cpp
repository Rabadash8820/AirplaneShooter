#include "MenuState.h"

#include "States.h"
#include "..\ResourceIds\Textures.h"
#include "..\ResourceIds\Fonts.h"

#include <Utility.h>

#include <SFML\Graphics\Text.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>

#include <string>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
MenuState::MenuState(StateManager& manager, Context context) :
	State(manager, context),
	_background((*context.textures)[Textures::TitleScreen])
{	
	// Define the Menu option buttons
	Text play("Play", (*context.fonts)[Fonts::Main]);
	Utility::centerOrigin(play);
	play.setPosition(context.window->getView().getSize() / 2.f);
	_options.push_back(play);

	Text exit("Exit", (*context.fonts)[Fonts::Main]);
	Utility::centerOrigin(exit);
	exit.setPosition(play.getPosition() + sf::Vector2f(0.f, 30.f));
	_options.push_back(exit);

	updateOptionText();
}
bool MenuState::handleEvent(const Event& e) {
	// Don't let other states handle non-Keyboard events
	if (e.type != Event::KeyPressed)
		return false;

	// Menu selection events
	if (e.key.code == Keyboard::Up) {
		_currentOption = (_currentOption + _options.size() - 1) % _options.size();
		updateOptionText();
	}
	else if (e.key.code == Keyboard::Down) {
		_currentOption = (_currentOption + 1) % _options.size();
		updateOptionText();
	}
	else if (e.key.code == Keyboard::Return)
		changeState();

	// Allow other States to handle KeyPress events
	return true;
}
bool MenuState::update(Time dt) {
	// Allow other States to update
	return true;
}
void MenuState::draw() {
	RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(_background);

	for (const sf::Text& text : _options)
		window.draw(text);
}

// HELPER FUNCTIONS
void MenuState::updateOptionText() {
	if (_options.empty())
		return;

	// Highlight only the currently selected option
	for (Text& text : _options)
		text.setColor(Color::White);
	_options[_currentOption].setColor(Color::Red);
}
void MenuState::changeState() {
	// Push/pop game States corresponding to the currently selected Option
	switch (_currentOption) {
	case Options::Play:
		requestPopState();
		requestPushState(States::Game);
		break;
	case Options::Exit:
		requestPopState();
		break;
	}
}
