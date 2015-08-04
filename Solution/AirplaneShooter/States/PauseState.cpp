#include "PauseState.h"

#include "States.h"
#include "..\ResourceIds\Fonts.h"
#include "..\ResourceIds\Textures.h"

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

PauseState::PauseState(Game2D::StateManager& manager, Context context) :
	State(manager, context),
	_pauseText("Game Paused", context.fonts->get(Fonts::Main), 70)
{
	// Initialize the background Sprite
	_background.setFillColor(Color(0, 0, 0, 150));

	// Initialize the Pause text
	Vector2f windowSize(context.window->getSize());
	Utility::centerOrigin(_pauseText);
	_pauseText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

	// Define the menu Buttons
	shared_ptr<Button> resume = make_shared<Button>(
		context.fonts->get(Fonts::Main),
		*context.textures,
		Textures::ButtonUnselected);
	resume->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 75);
	resume->setText("Resume Playing");
	resume->setTexture(Button::State::Selected, Textures::ButtonSelected);
	resume->setTexture(Button::State::Pressed,  Textures::ButtonPressed);
	resume->setCallback([this]() {
		requestPopState();
	});

	shared_ptr<Button> menu = make_shared<Button>(
		context.fonts->get(Fonts::Main),
		*context.textures,
		Textures::ButtonUnselected);
	menu->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
	menu->setText("Main Menu");
	menu->setTexture(Button::State::Selected, Textures::ButtonSelected);
	menu->setTexture(Button::State::Pressed,  Textures::ButtonPressed);
	menu->setCallback([this]() {
		requestClearStates();
		requestPushState(States::MainMenu);
	});

	// Pack buttons into the GUI Container
	_guiContainer.pack(resume);
	_guiContainer.pack(menu);
}

bool PauseState::handleEvent(const sf::Event& e) {
	_guiContainer.handleEvent(e);

	// Don't allow other States to handle this Event
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
