#include "DesertMap.h"
#include "Aircraft.h"
#include <Render/Brush.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <cassert>

// Define a general macro to get the current working directory
#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace sf;
using namespace Game2D;
using namespace std;

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
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
	DesertMap::~DesertMap() {}

	// INTERFACE FUNCTIONS
	void DesertMap::updateCurrent(Time dt) {

		// Adjust the player's velocity according to keyboard input
		_player->Velocity = Vector2f(0.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
			_player->Velocity = -Vector2f(_playerSpeed, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
			_player->Velocity = Vector2f(_playerSpeed, 0.f);

		// Adjust the player's velocity according to their position in the Map
		float playerPos = _player->getPosition().x;
		if (playerPos <= _worldBounds.left + BOUNDARY_OFFSET || _worldBounds.left + _worldBounds.width - BOUNDARY_OFFSET <= playerPos) {
			float reverse = -_player->Velocity.x;
			_player->Velocity = Vector2f(reverse, 0.f);
		}

		// Scroll the map
		ScrollingMap::updateCurrent(dt);
	}

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
		Brush::Ptr background(
			new Brush(desertTexture, desertBounds));
		background->setPosition(_worldBounds.left, _worldBounds.top);
		_sceneLayers[BACKGROUND]->attachChild(std::move(background));

		// Add a node for the leader Aircraft and assign it to the Player
		Aircraft::Ptr leader(new Aircraft(Aircraft::EAGLE, _textures));
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
	string DesertMap::projectDirectory() {
		char currDir[FILENAME_MAX];
		GetCurrentDir(currDir, sizeof(currDir));
		// Make some assertion here...
		return currDir;
	}

}