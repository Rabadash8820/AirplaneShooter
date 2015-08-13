#include "Player.h"

#include "Render\Aircraft.h"
#include "Categories.h"

#include <SceneNode.h>

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
	Command moveLeft("Move Left", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(-a.getMaxSpeed(), 0.f));
	});
	Command moveRight("Move Right", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(a.airSpeed, 0.f));
	});
	Command moveUp("Move Up", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(0.f, -a.airSpeed));
	});
	Command moveDown("Move Down", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(0.f, a.airSpeed));
	});

	// Define weapon Commands
	Command fireBullets("Fire Bullets", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.fire();
	});
	Command launchMissile("Launch Missile", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.launchMissile();
	});

	// Bind these commands to an ActionId
	bindCommand(moveLeft,      MoveLeft);
	bindCommand(moveRight,     MoveRight);
	bindCommand(moveUp,	       MoveUp);
	bindCommand(moveDown,	   MoveDown);
	bindCommand(fireBullets,   FireBullets);
	bindCommand(launchMissile, LaunchMissile);

	// Bind Keys to each Action
	bindKey(Keyboard::A,	 MoveLeft);
	bindKey(Keyboard::D,	 MoveRight);
	bindKey(Keyboard::W,	 MoveUp);
	bindKey(Keyboard::S,	 MoveDown);
	bindKey(Keyboard::Left,  MoveLeft);
	bindKey(Keyboard::Right, MoveRight);
	bindKey(Keyboard::Up,	 MoveUp);
	bindKey(Keyboard::Down,  MoveDown);
	bindKey(Keyboard::Space, FireBullets);
	bindKey(Keyboard::M,	 LaunchMissile);

	// Also set these as the default Key bindings
	bindDefaultKey(Keyboard::A,		MoveLeft);
	bindDefaultKey(Keyboard::D,		MoveRight);
	bindDefaultKey(Keyboard::W,		MoveUp);
	bindDefaultKey(Keyboard::S,		MoveDown);
	bindDefaultKey(Keyboard::Left,  MoveLeft);
	bindDefaultKey(Keyboard::Right, MoveRight);
	bindDefaultKey(Keyboard::Up,	MoveUp);
	bindDefaultKey(Keyboard::Down,	MoveDown);
	bindDefaultKey(Keyboard::Space, FireBullets);
	bindDefaultKey(Keyboard::M,		LaunchMissile);

	// Assign the category for the player's aircraft to all Commands
	for (auto& pair : _commandBindings)
		pair.second.category = Categories::PlayerAircraft;
}
vector<CommandId> Player::commands() const {
	vector<CommandId> ids = { MoveLeft, MoveRight, MoveUp, MoveDown, FireBullets, LaunchMissile };
	return ids;
}

// HELPER FUNCTIONS
void Player::handleKeyPress(const Event::KeyEvent& key, queue<Command>& commands) const {
	switch (key.code) {
	case Keyboard::P: {
		// Print the player Aircraft's location to the console
		Command printPos(
			"Print Player Data",
			[](SceneNode& sn, Time) {
				Aircraft& a = static_cast<Aircraft&>(sn);
				cout << endl
					 << "Position (x, y): " << a.getPosition().x << ", " << a.getPosition().y << endl
					 << "Velocity (x, y): " << a.getVelocity().x << ", " << a.getVelocity().y << endl;
			},
			Categories::PlayerAircraft
		);
		commands.push(printPos);
		break;
	}
	case Keyboard::E:{
		// Print the locations of each Enemy Aircraft to the console
		Command printPos(
			"Print Enemy Data",
			[](SceneNode& sn, Time) {
				Aircraft& a = static_cast<Aircraft&>(sn);
				cout << "Position (x, y): " << a.getPosition().x << ", " << a.getPosition().y << endl
					<< "Velocity (x, y): "  << a.getVelocity().x << ", " << a.getVelocity().y << endl;
			},
			Categories::EnemyAircraft
		);
		commands.push(printPos);
		break;
	}
	}
}
