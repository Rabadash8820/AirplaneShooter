#include "AirplaneShooter.h"
#include "DesertMap.h"
#include "Aircraft.h"
#include "Categories.h"
#include <Input\Command.h>
#include <Input\KeyBinding.h>
#include <memory>

using namespace Shooter;
using namespace Game2D;
using namespace sf;

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
	Command moveLeft(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(-a.airSpeed, 0.f); },
		PlayerAircraft);
	Command moveRight(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(a.airSpeed, 0.f); },
		PlayerAircraft);
	Command moveUp(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(0.f, -a.airSpeed); },
		PlayerAircraft);
	Command moveDown(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(0.f, -a.airSpeed); },
		PlayerAircraft);

	// Define KeyBindings for those Commands
	_keyBindings.push_back(KeyBinding(sf::Keyboard::A,	   moveLeft));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::D,	   moveRight));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::W,	   moveUp));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::S,	   moveDown));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Left,  moveLeft));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Right, moveRight));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Up,	   moveUp));
	_keyBindings.push_back(KeyBinding(sf::Keyboard::Down,  moveDown));
}
