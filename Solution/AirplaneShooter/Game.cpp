#include "Game.h"
#include "DesertMap.h"
#include "Aircraft.h"
#include "Categories.h"
#include "States\States.h"
#include "States\TitleState.h"
#include "ResourceIds\Fonts.h"
#include <Input\Command.h>
#include <Input\KeyBinding.h>
#include <memory>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Game::Game() :
	Application(VideoMode(640, 480), "Airplane Shooter")
{
	_window.setKeyRepeatEnabled(false);
	
	// Get resource directories
	string currDir    = currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string shaderDir  = currDir + "\\Resources\\Shaders\\";
	string soundDir   = currDir + "\\Resources\\Sounds\\";
	string fontDir    = currDir + "\\Resources\\Fonts\\";

	// Load textures
	_textures.load(Textures::Desert,	  textureDir + "Desert.png");
	_textures.load(Textures::Eagle,		  textureDir + "Eagle.png");
	_textures.load(Textures::Raptor,	  textureDir + "Raptor.png");
	_textures.load(Textures::TitleScreen, textureDir + "TitleScreen.png");

	// Load fonts
	_fonts.load(Fonts::Main, fontDir + "Sansation.ttf");

	// Initialize the statistics text
	_statisticsText.setFont(_fonts[Fonts::Main]);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10u);

	// Register states and start in the Title state
	registerStates();
	_stateManager.push(States::Title);
}
Game::~Game() {}

// INITIALIZATION FUNCTIONS
void Game::initKeyBindings() {
	// Define Commands
	Command moveLeft(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(-a.airSpeed, 0.f); },
		Categories::PlayerAircraft);
	Command moveRight(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(a.airSpeed, 0.f); },
		Categories::PlayerAircraft);
	Command moveUp(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(0.f, -a.airSpeed); },
		Categories::PlayerAircraft);
	Command moveDown(
		[](SceneNode& node, Time dt) {
			Aircraft& a = static_cast<Aircraft&>(node);
			a.velocity += Vector2f(0.f, a.airSpeed); },
		Categories::PlayerAircraft);

	// Define KeyBindings for those Commands
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::A,	   moveLeft));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::D,	   moveRight));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::W,	   moveUp));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::S,	   moveDown));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::Left,  moveLeft));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::Right, moveRight));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::Up,	   moveUp));
	//_keyBindings.push_back(KeyBinding(sf::Keyboard::Down,  moveDown));
}
void Game::registerStates() {
	_stateManager.registerState<TitleState>(States::Title);
}