#include "DesertMap.h"
#include "Aircraft.h"
#include <Brush.h>

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	DesertMap::DesertMap(sf::View view) :
		Game2D::ScrollingMap(
			sf::Vector2f(0.f, -50.f),
			view,
			sf::FloatRect(0.f, 0.f, view.getSize().x, 2000.f),
			3),
		_playerSpeed(40.f)
	{
		sf::Vector2f viewSize = _view.getSize();
		sf::Vector2f spawn(viewSize.x / 2, _worldBounds.height - viewSize.y / 2);
		_playerSpawn = spawn;

	}
	DesertMap::~DesertMap() {}

	// INTERFACE FUNCTIONS
	void DesertMap::postScrollUpdate(sf::Time dt) {
		// Move the player horizontally
		float playerPos = _player->getPosition().x;
		if (playerPos <= _worldBounds.left + BOUNDARY_OFFSET || _worldBounds.left - BOUNDARY_OFFSET <= playerPos)
			_player->Velocity.x = 0.f;
	}

	// HELPER FUNCTIONS
	void DesertMap::loadResources() {
		// Load texture resources
		_textures.load(ResourceIDs::Texture::DESERT, "..\\..\\Resources\\Textures\\Desert.png");
		_textures.load(ResourceIDs::Texture::EAGLE, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\AirplaneShooter\\Resources\\Textures\\Eagle.png");
		_textures.load(ResourceIDs::Texture::RAPTOR, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\AirplaneShooter\\Resources\\Textures\\Raptor.png");
	}
	void DesertMap::buildScene() {
		// Set the window's View
		_view.setCenter(_playerSpawn);

		// Add a node for the background, and tile its texture
		sf::Texture desert = _textures[ResourceIDs::Texture::DESERT];
		std::unique_ptr<Game2D::Brush> background(
			new Game2D::Brush(desert, sf::IntRect(_worldBounds)));
		background->setPosition(_worldBounds.left, _worldBounds.top);
		_sceneLayers[BACKGROUND]->attachChild(std::move(background));
		desert.setRepeated(true);

		// Add a node for the player's Aircraft
		std::unique_ptr<Aircraft> plane(new Aircraft(Aircraft::EAGLE, _textures));
		plane->setPosition(_playerSpawn);
		plane->Velocity = sf::Vector2f(_playerSpeed, _scrollSpeed);
		_player = plane.get();
		_sceneLayers[AIR]->attachChild(std::move(plane));

		// Add nodes for the player's escort Aircraft
		std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::RAPTOR, _textures));
		std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::RAPTOR, _textures));
		leftEscort->setPosition(-80.f, 50.f);
		rightEscort->setPosition(80.f, 50.f);
		leftEscort->Velocity = sf::Vector2f(_playerSpeed, _scrollSpeed);
		rightEscort->Velocity = sf::Vector2f(_playerSpeed, _scrollSpeed);
		_player->attachChild(std::move(leftEscort));
		_player->attachChild(std::move(rightEscort));

	}

}