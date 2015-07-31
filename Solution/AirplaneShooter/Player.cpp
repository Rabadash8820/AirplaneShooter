#include "Player.h"
#include "Aircraft.h"
#include "Categories.h"

#include <iostream>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Player::Player() {
	// Define Commands
	Command moveLeft([](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(-a.airSpeed, 0.f);
	});
	Command moveRight([](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(a.airSpeed, 0.f);
	});
	Command moveUp([](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(0.f, -a.airSpeed);
	});
	Command moveDown([](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(0.f, a.airSpeed);
	});

	// Define KeyBindings for those Commands
	_keyBindings.push_back(KeyBinding(sf::Keyboard::A,	   moveLeft));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::D,	   moveRight));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::W,	   moveUp));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::S,	   moveDown));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Left,  moveLeft));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Right, moveRight));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Up,	   moveUp));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Down, moveDown));

	// Assign the category for the player's aircraft to all Commands
	for (auto& pair : _keyBindings)
		pair.command.setCategory(Categories::PlayerAircraft);
}
void Player::handleRealtimeInput(std::queue<Game2D::Command>& commands) const {
	// Push keyboard events to the Command queue
	for (auto& binding : _keyBindings) {
		if (Keyboard::isKeyPressed(binding.key))
			commands.push(binding.command);
	}
}

// HELPER FUNCTIONS
void Player::handleKeyPress(const Event::KeyEvent& key, queue<Command>& commands) const {
	switch (key.code) {
	case Keyboard::P:
		// Print the player Aircraft's location to the console
		Command printPos([](SceneNode& sn, Time) {
			cout << sn.getPosition().x << ","
				 << sn.getPosition().y << endl;
		});
		printPos.setCategory(Categories::PlayerAircraft);
		commands.push(printPos);
		break;
	}
}
