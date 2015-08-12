#include "PauseState.h"

#include "..\Ids\FontId.h"
#include "..\Ids\TextureId.h"
#include "MenuState.h"

#include <Utility.h>

#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>

#include <memory>

using namespace Game2D;
using namespace Game2D::GUI;
using namespace Shooter;
using namespace sf;
using namespace std;

PauseState::PauseState(Game2D::StateManager& manager) :
	BaseState(manager),
	_pauseText("Game Paused", getContext().fonts->get(FontId::Main), 70)
{
	// Initialize the background Sprite
	_background.setFillColor(Color(0, 0, 0, 150));

	// Initialize the Pause text
	Vector2f windowSize(getContext().window->getSize());
	Utility::centerOrigin(_pauseText);
	_pauseText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

	// Define the menu Buttons
	Font& main = getContext().fonts->get(FontId::Main);
	shared_ptr<Button> resume = make_shared<Button>(main, *getContext().buttonTextures);
	resume->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 75);
	resume->setText("Resume Playing");
	resume->setCallback([this]() {
		requestPopState();
	});

	shared_ptr<Button> menu = make_shared<Button>(main, *getContext().buttonTextures);
	menu->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
	menu->setText("Main Menu");
	menu->setCallback([this]() {
		requestClearStates();
		requestPushState<MenuState>();
	});

	// Pack buttons into the GUI Container
	_guiContainer.pack(resume);
	_guiContainer.pack(menu);
}

bool PauseState::handleEvent(const sf::Event& e) {
	// If player hits Escape again then return to the game
	if (e.type == e.KeyPressed && e.key.code == Keyboard::Escape)
		requestPopState();

	// Let the GUI (only) handle all other EVents
	_guiContainer.handleEvent(e);
	return false;
}
bool PauseState::update(sf::Time dt) {
	// Don't allow other States to update
	return false;
}
void PauseState::draw() {
	// Set the size of the background fill
	RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());
	_background.setSize(Vector2f(window.getView().getSize()));

	// Draw objects
	window.draw(_background);
	window.draw(_pauseText);
	window.draw(_guiContainer);
}
