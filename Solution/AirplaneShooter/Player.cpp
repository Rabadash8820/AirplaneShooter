#include "Player.h"

#include "Aircraft.h"
#include "Categories.h"

#include <Input\ActionId.h>
#include <Render\SceneNode.h>

#include <SFML\System\Time.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Window\Keyboard.hpp>

#include <iostream>
#include <cassert>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Player::Player() {
	// Define movement Commands
	Command moveLeftComm("Move Left", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(-a.airSpeed, 0.f);
	});
	Command moveRightComm("Move Right", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(a.airSpeed, 0.f);
	});
	Command moveUpComm("Move Up", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(0.f, -a.airSpeed);
	});
	Command moveDownComm("Move Down", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.velocity += Vector2f(0.f, a.airSpeed);
	});

	// Bind these commands to an ActionId
	bindCommand(moveLeftComm,  MoveLeft);
	bindCommand(moveRightComm, MoveRight);
	bindCommand(moveUpComm,	   MoveUp);
	bindCommand(moveDownComm,  MoveDown);

	// Bind Keys to each Action
	bindKey(Keyboard::A,	 MoveLeft);
	bindKey(Keyboard::D,	 MoveRight);
	bindKey(Keyboard::W,	 MoveUp);
	bindKey(Keyboard::S,	 MoveDown);
	bindKey(Keyboard::Left,  MoveLeft);
	bindKey(Keyboard::Right, MoveRight);
	bindKey(Keyboard::Up,	 MoveUp);
	bindKey(Keyboard::Down,	 MoveDown);

	// Assign the category for the player's aircraft to all Commands
	for (auto& pair : _commandBindings)
		pair.second.category = Categories::PlayerAircraft;
}

// HELPER FUNCTIONS
void Player::handleKeyPress(const Event::KeyEvent& key, queue<Command>& commands) const {
	switch (key.code) {
	case Keyboard::P:
		// Print the player Aircraft's location to the console
		Command printPos(
			"Print Position",
			[](SceneNode& sn, Time) {
				cout << sn.getPosition().x << ","
					 << sn.getPosition().y << endl;
			},
			Categories::PlayerAircraft
		);
		commands.push(printPos);
		break;
	}
}
