#include "DesertMap.h"

#include "Aircraft.h"
#include "ResourceIds\Textures.h"
#include "ResourceIds\Fonts.h"
#include "Categories.h"
#include <Render/Brush.h>
#include <memory>
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
		3)
{
	// Align the player spawn point with the center of the View
	_view = _window->getDefaultView();
	float playerSpawnX = _worldBounds.left + _view.getSize().x / 2.f;
	float playerSpawnY = _worldBounds.top + _worldBounds.height - _view.getSize().y / 2.f;
	_playerSpawn = Vector2f(playerSpawnX, playerSpawnY);
	_view.setCenter(_playerSpawn);
}
void DesertMap::handleEvent(const sf::Event& e) {
	Shooter::Categories* c = reinterpret_cast<Shooter::Categories*>(_categories.get());
	switch (e.type) {
	case Event::KeyPressed:
		if (e.key.code == Keyboard::P) {
			Command output;
			output.Action = [](SceneNode& s, Time) {
				cout << s.getPosition().x << "," << s.getPosition().y << endl;
			};
			output.Category = c->PlayerAircraft();
			_commands.push(output);

		}
		break;
	}
	
}
void DesertMap::handleRealtimeInput() {
	Shooter::Categories* c = reinterpret_cast<Shooter::Categories*>(_categories.get());
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		Command moveLeft;
		//moveLeft.Action = ;
		moveLeft.Category = c->PlayerAircraft();
		_commands.push(moveLeft);
	}
}

// HELPER FUNCTIONS
void DesertMap::loadResources() {
	// Load texture resources
	_textures.load(ResourceIDs::Texture::DESERT, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Desert.png");
	_textures.load(ResourceIDs::Texture::EAGLE, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Eagle.png");
	_textures.load(ResourceIDs::Texture::RAPTOR, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Raptor.png");
}
void DesertMap::buildScene() {
	// Add a node for the background, and tile its texture
	Texture& desertTexture = _textures[Textures::Desert];
	IntRect desertBounds(_worldBounds);
	desertTexture.setRepeated(true);
	Brush::Ptr background(
		new Brush(desertTexture, desertBounds, unique_ptr<Categories>(new Categories())));
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
void DesertMap::updateCurrent(Time dt) {
	// Scroll the map
	ScrollingMap::updateCurrent(dt);

	// Reset player's velocity
	_player->Velocity = Vector2f(0.f, 0.f);

	// Adjust the player's velocity according to keyboard input
	_player->Velocity = Vector2f(0.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		_player->Velocity = -Vector2f(_playerSpeed, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		_player->Velocity = Vector2f(_playerSpeed, 0.f);

	// Adjust the player's velocity according to their position in the Map
	float playerPos = _player->getPosition().x;
	if (playerPos <= _worldBounds.left + BORDER_OFFSET || _worldBounds.left + _worldBounds.width - BORDER_OFFSET <= playerPos) {
		float reverse = -_player->Velocity.x;
		_player->Velocity = Vector2f(reverse, 0.f);
	}
	string DesertMap::projectDirectory() {
		char currDir[FILENAME_MAX];
		GetCurrentDir(currDir, sizeof(currDir));
		// Make some assertion here...
		return currDir;
	}

	// Scroll the map
	ScrollingMap::updateCurrent(dt);
}