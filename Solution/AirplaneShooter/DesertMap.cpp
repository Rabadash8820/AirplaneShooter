#include "DesertMap.h"
#include "Aircraft.h"
#include "Categories.h"
#include <Render/Brush.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <cassert>
#include <iostream>

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
		3),
	_playerSpeed(40.f)
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
	_player->velocity = -Vector2f(0.f, 0.f);
	
	// Do updates in response to Commands
	updateOnCommands(dt);

	adjustPlayer(dt);

	// Do "normal" updates
	ScrollingMap::updateCurrent(dt);
}
DesertMap::~DesertMap() {}

// HELPER FUNCTIONS
void DesertMap::loadResources() {
	// Get resource directories
	string textureDir = projectDirectory() + "\\Resources\\Textures\\";

	// Load texture resources
	_textures.load(ResourceIDs::Texture::DESERT, textureDir + "Desert.png");
	_textures.load(ResourceIDs::Texture::EAGLE,  textureDir + "Eagle.png");
	_textures.load(ResourceIDs::Texture::RAPTOR, textureDir + "Raptor.png");
}
void DesertMap::buildScene() {
	// Add a node for the background, and tile its texture
	Texture& desertTexture = _textures[ResourceIDs::Texture::DESERT];
	IntRect desertBounds(_worldBounds);
	desertTexture.setRepeated(true);
	Brush::Ptr background(new Brush(desertTexture, desertBounds));
	background->setPosition(_worldBounds.left, _worldBounds.top);
	_sceneLayers[BACKGROUND]->attachChild(std::move(background));

	// Add a node for the leader Aircraft and assign it to the Player
	Aircraft::Ptr leader(new Aircraft(Aircraft::EAGLE, _textures));
	leader->airSpeed = _playerSpeed;
	leader->setPosition(_playerSpawn);
	_player = leader.get();
	_sceneLayers[AIR]->attachChild(std::move(leader));

	// Add nodes for the player's escort Aircraft
	Aircraft::Ptr leftEscort(new Aircraft(Aircraft::RAPTOR, _textures));
	Aircraft::Ptr rightEscort(new Aircraft(Aircraft::RAPTOR, _textures));
	leftEscort->setPosition(-80.f, 50.f);
	rightEscort->setPosition(80.f, 50.f);
	_player->attachChild(std::move(leftEscort));
	_player->attachChild(std::move(rightEscort));

	// Make things scroll
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
	pos.y = max(pos.x, viewBounds.top  + BORDER_OFFSET);
	pos.y = min(pos.x, viewBounds.top  + viewBounds.height - BORDER_OFFSET);
	_player->setPosition(pos);
}
void DesertMap::handleEvent(const Event& e) {
	switch (e.type) {
	case Event::KeyPressed:
		switch (e.key.code) {
		case Keyboard::P: {
			Command output(
				[](SceneNode& s, Time) {
					cout << s.getPosition().x << ", " << s.getPosition().y << endl; },
					PlayerAircraft);
			_commands.push(output);
			break;
		}
		default:
			break;
		}
		break;
	default:
		break;
	}
}
