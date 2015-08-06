#include "DesertMap.h"

#include "Aircraft.h"
#include "ResourceIds\Textures.h"
#include "ResourceIds\Fonts.h"
#include "Categories.h"

#include <Render\Brush.h>
#include <Utility.h>
#include <Map\ScrollingMap.h>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>

#include <string>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
DesertMap::DesertMap(RenderWindow* window) :
	ScrollingMap(
		Vector2f(0.f, -50.f),
		window,
		FloatRect(0.f, 0.f, window->getDefaultView().getSize().x, 2000.f),
		3)
{
	// Align the player spawn point with the center of the View
	_view = _window->getDefaultView();
	float playerSpawnX = _worldBounds.left + _view.getSize().x / 2.f;
	float playerSpawnY = _worldBounds.top + _worldBounds.height - _view.getSize().y / 2.f;
	_playerSpawn = Vector2f(playerSpawnX, playerSpawnY);
	_view.setCenter(_playerSpawn);
}
void DesertMap::updateCurrent(Time dt) {
	// Prepare for updates
	_player->velocity = Vector2f(0.f, 0.f);
	
	// Do updates in response to Commands
	updateOnCommands(dt);

	adjustPlayer(dt);

	// Do "normal" updates
	ScrollingMap::updateCurrent(dt);
}

// HELPER FUNCTIONS
void DesertMap::loadResources() {
	// Get resource directories
	string currDir    = Utility::currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string shaderDir  = currDir + "\\Resources\\Shaders\\";
	string soundDir = currDir + "\\Resources\\Sounds\\";
	string fontDir = currDir + "\\Resources\\Fonts\\";

	// Load textures
	_textures.load(Textures::Desert, textureDir + "Desert.png");
	_textures.load(Textures::Eagle,  textureDir + "Eagle.png");
	_textures.load(Textures::Raptor, textureDir + "Raptor.png");

	// Load fonts
	_fonts.load(Fonts::Main, fontDir + "Sansation.ttf");
}
void DesertMap::buildScene() {
	// Add a node for the background, and tile its texture
	Texture& desertTexture = _textures[Textures::Desert];
	IntRect desertBounds(_worldBounds);
	desertTexture.setRepeated(true);
	Brush::Ptr background(new Brush(desertTexture, desertBounds));
	background->setPosition(_worldBounds.left, _worldBounds.top);
	_sceneLayers[BACKGROUND]->attachChild(move(background));

	// Add a node for the leader Aircraft and assign it to the Player
	Aircraft::Ptr leader(new Aircraft(Aircraft::Type::EAGLE, _textures, _fonts));
	leader->airSpeed = PLAYER_SPEED;
	leader->setPosition(_playerSpawn);
	_player = leader.get();
	_sceneLayers[AIR]->attachChild(move(leader));

	// Add nodes for the player's escort Aircraft
	Aircraft::Ptr leftEscort( new Aircraft(Aircraft::Type::RAPTOR, _textures, _fonts));
	Aircraft::Ptr rightEscort(new Aircraft(Aircraft::Type::RAPTOR, _textures, _fonts));
	leftEscort->setPosition(-80.f, 50.f);
	rightEscort->setPosition(80.f, 50.f);
	_player->attachChild(move(leftEscort));
	_player->attachChild(move(rightEscort));

	// Do base building
	ScrollingMap::buildScene();
}
void DesertMap::adjustPlayer(Time dt) {
	// Reduce the playerAircraft's velocity if they are moving diagonally
	Vector2f playerV = _player->velocity;
	if (playerV.x != 0 && playerV.y != 0)
		_player->velocity = playerV / sqrt(2.f);
	
	// Adjust the playerAircraft's position if they cross the View's boundary
	Vector2f pos = _player->getPosition();
	FloatRect viewBounds(
		_view.getCenter() - _view.getSize() / 2.f,
		_view.getSize());
	pos.x = max(pos.x, viewBounds.left + BORDER_OFFSET);
	pos.x = min(pos.x, viewBounds.left + viewBounds.width - BORDER_OFFSET);
	pos.y = max(pos.y, viewBounds.top  + BORDER_OFFSET);
	pos.y = min(pos.y, viewBounds.top  + viewBounds.height - BORDER_OFFSET);
	_player->setPosition(pos);
}
