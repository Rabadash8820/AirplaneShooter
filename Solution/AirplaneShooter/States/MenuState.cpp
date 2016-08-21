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
using namespace Game2D::GUI;
using namespace sf;
using namespace std;

// INTERFACE
MenuState::MenuState(StateManager& manager, Context context) :
	State(manager, context),
	_background((*context.textures)[Textures::TitleScreen])
{	
	// Define the menu buttons
	shared_ptr<Button> play = make_shared<Button>(
		context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	play->setText("Play");
	play->setPosition(100, 250);
	play->setTexture(Button::State::Selected, Textures::ButtonSelected);
	play->setTexture(Button::State::Pressed,  Textures::ButtonPressed);
	play->setCallback([this]() {
		requestPopState();
		requestPushState(States::Game);
	});

	shared_ptr<Button> settings = make_shared<Button>(
		context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	settings->setText("Settings");
	settings->setPosition(100, 300);
	settings->setTexture(Button::State::Selected, Textures::ButtonSelected);
	settings->setTexture(Button::State::Pressed, Textures::ButtonPressed);
	settings->setCallback(bind(
		&MenuState::requestPushState, this,
		States::SettingsMenu));

	shared_ptr<Button> exit = make_shared<Button>(
		context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	exit->setText("Exit");
	exit->setPosition(100, 350);
	exit->setTexture(Button::State::Selected, Textures::ButtonSelected);
	exit->setTexture(Button::State::Pressed, Textures::ButtonPressed);
	exit->setCallback(bind(&MenuState::requestPopState, this));

	// Pack buttons into the GUI Container
	_guiContainer.pack(play);
	_guiContainer.pack(settings);
	_guiContainer.pack(exit);
}
bool MenuState::handleEvent(const Event& e) {
	_guiContainer.handleEvent(e);

	// Don't allow other States to handle this Event
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
	window.draw(_guiContainer);
}
