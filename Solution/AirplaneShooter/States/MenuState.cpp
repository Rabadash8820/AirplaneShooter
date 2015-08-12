#include "MenuState.h"

#include "GameState.h"
#include "SettingsState.h"
#include "..\Ids\TextureId.h"
#include "..\Ids\FontId.h"

#include <Utility.h>

#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Text.hpp>

#include <string>

using namespace Shooter;
using namespace Game2D;
using namespace Game2D::GUI;
using namespace sf;
using namespace std;

// INTERFACE
MenuState::MenuState(StateManager& manager) :
	BaseState(manager),
	_background(getContext().textures->get(TextureId::TitleScreen))
{	
	// Define the menu buttons
	Font& main = getContext().fonts->get(FontId::Main);
	shared_ptr<Button> play = make_shared<Button>(main, *getContext().buttonTextures);
	play->setText("Play");
	play->setPosition(100, 250);
	play->setCallback([this]() {
		requestPopState();
		requestPushState<GameState>();
	});

	shared_ptr<Button> settings = make_shared<Button>(main, *getContext().buttonTextures);
	settings->setText("Settings");
	settings->setPosition(100, 300);
	settings->setCallback([this]() {
		requestPushState<SettingsState>();
	});

	shared_ptr<Button> exit = make_shared<Button>(main, *getContext().buttonTextures);
	exit->setText("Exit");
	exit->setPosition(100, 350);
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
