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
	bindPlayerCommands();
	bindDebugCommands();
}
vector<CommandId> Player::commands() const {
	vector<CommandId> ids = { MoveLeft, MoveRight, MoveUp, MoveDown, FireBullets, LaunchMissile };
	return ids;
}
bool Player::isRealtime(CommandId command) const {
	bool realTime = (command == MoveLeft ||
					command == MoveRight ||
					command == MoveDown ||
					command == MoveUp ||
					command == FireBullets);
	return realTime;
}

// HELPER FUNCTIONS
void Player::bindPlayerCommands() {
	// Define movement Commands
	Command moveLeftComm("Move Left", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(-a.getMaxSpeed(), 0.f));
	});
	Command moveRightComm("Move Right", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(a.airSpeed, 0.f));
	});
	Command moveUpComm("Move Up", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(0.f, -a.airSpeed));
	});
	Command moveDownComm("Move Down", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.setVelocity(a.getVelocity() + Vector2f(0.f, a.airSpeed));
	});

	// Define weapon Commands
	Command fireBulletsComm("Fire Bullets", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.fire();
	});
	Command fireMissileComm("Launch Missile", [](SceneNode& node, Time dt) {
		Aircraft& a = static_cast<Aircraft&>(node);
		a.launchMissile();
	});

	// Bind these commands to an ActionId
	bindCommand(moveLeftComm, MoveLeft);
	bindCommand(moveRightComm, MoveRight);
	bindCommand(moveUpComm, MoveUp);
	bindCommand(moveDownComm, MoveDown);
	bindCommand(fireBulletsComm, FireBullets);
	bindCommand(fireMissileComm, LaunchMissile);

	// Also set these as the default Key bindings
	bindDefaultKey(Keyboard::A, MoveLeft);
	bindDefaultKey(Keyboard::D, MoveRight);
	bindDefaultKey(Keyboard::W, MoveUp);
	bindDefaultKey(Keyboard::S, MoveDown);
	bindDefaultKey(Keyboard::Left, MoveLeft);
	bindDefaultKey(Keyboard::Right, MoveRight);
	bindDefaultKey(Keyboard::Up, MoveUp);
	bindDefaultKey(Keyboard::Down, MoveDown);
	bindDefaultKey(Keyboard::Space, FireBullets);
	bindDefaultKey(Keyboard::M, LaunchMissile);

	// Assign the category for the player's aircraft to all Commands
	for (auto& pair : _commandBindings)
		pair.second.category = Categories::PlayerAircraft;
}
void Player::bindDebugCommands() {
	// Define and bind some debug Commands
	Command printPlayerComm(
		"Print Player Data",
		[](SceneNode& sn, Time) {
			Aircraft& a = static_cast<Aircraft&>(sn);
			Vector2f pos = a.getPosition();
			Vector2f vel = a.getVelocity();
			cout << endl
				 << "Position (x, y): " << pos.x << ", " << pos.y << endl
				 << "Velocity (x, y): " << vel.x << ", " << vel.y << endl;
		},
		Categories::PlayerAircraft
	);
	Command printEnemyComm(
		"Print Enemy Data",
		[](SceneNode& sn, Time) {
			Aircraft& a = static_cast<Aircraft&>(sn);
			Vector2f pos = a.getPosition();
			Vector2f vel = a.getVelocity();
			cout << "Position (x, y): " << pos.x << ", " << pos.y << endl
				 << "Velocity (x, y): " << vel.x << ", " << vel.y << endl;
		},
		Categories::EnemyAircraft
	);

	// Bind these commands to an ActionId
	bindCommand(printPlayerComm, PrintPlayerData);
	bindCommand(printEnemyComm, PrintEnemyData);

	// Bind Keys to each Action
	bindKey(Keyboard::P, PrintPlayerData);
	bindKey(Keyboard::E, PrintEnemyData);
}
