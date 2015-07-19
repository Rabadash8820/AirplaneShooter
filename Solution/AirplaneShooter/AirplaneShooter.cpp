#include "AirplaneShooter.h"
#include "DesertMap.h"
#include <Command.h>
#include <KeyBinding.h>
#include <memory>

using namespace sf;
using namespace Game2D;

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	AirplaneShooter::AirplaneShooter() :
		Game(VideoMode(640, 480), "Airplane Shooter")
	{
		// Set the map for this game
		Map::Ptr desert(new DesertMap(&_window));
		this->setMap(std::move(desert));

		initKeyBindings();
	}
	AirplaneShooter::~AirplaneShooter() {}

	// INITIALIZATION FUNCTIONS
	void AirplaneShooter::initKeyBindings() {
		// Define Commands
		Command leftCommand(PlayerAircraft);
		Command rightCommand(PlayerAircraft);
		Command upCommand(PlayerAircraft);
		Command downCommand(PlayerAircraft);

		// Define KeyBindings for those Commands
		_keyBindings.insert(KeyBinding(sf::Keyboard::A,     leftCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::D,     rightCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::W,     upCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::S,     downCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::Left,  leftCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::Right, rightCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::Up,    upCommand));
		_keyBindings.insert(KeyBinding(sf::Keyboard::Down,  downCommand));
	}
}