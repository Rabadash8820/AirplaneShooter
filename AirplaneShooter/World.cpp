#include "World.h"
#include "ResourceIds.h"
#include <Brush.h>

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	World::World(sf::RenderWindow& w) :
		_window(w),
		_view(_window.getDefaultView()),
		_worldBounds(0.f, 0.f, _window.getSize().x, WORLD_HEIGHT),
		_playerSpawn(_worldBounds.width / 2.f,
					 _worldBounds.height - _view.getSize().y / 2.f),
		_player(nullptr)
	{
		loadTextures();
		buildScence();
	}
	World::~World() {}

	// INTERFACE FUNCTIONS
	void World::update(sf::Time dt) {
		// Scroll the view upwards
		_view.move(0.f, -_scrollSpeed * dt.asSeconds());

		// Move the player horizontally
		sf::Vector2f playerPos = _player->getPosition();
		if (playerPos.x <= _worldBounds.left + BOUNDARY_OFFSET ||
			_worldBounds.left - BOUNDARY_OFFSET <= playerPos.x)
			_player->Velocity.x = 0.f;

		// Update the other scene nodes
		_sceneTree.update(dt);
	}
	void World::render() {
		_window.draw(_sceneTree);
	}

	// HELPER FUNCTIONS
	void World::loadTextures() {
		// Load texture resources
		_textures.load(ResourceIDs::Texture::DESERT, "Resources/Texutres/Desert.png");
		_textures.load(ResourceIDs::Texture::EAGLE, "Resources/Texutres/Eagle.png");
		_textures.load(ResourceIDs::Texture::RAPTOR, "Resources/Texutres/Raptor.png");
	}
	void World::buildScence() {
		// Set the window's View
		_view.setCenter(_playerSpawn);
		_window.setView(_view);

		// Add each scene layer to the scene graph and layer array
		for (short L = 0; L < NUM_LAYERS; ++L) {
			Game2D::SceneNode::NodePtr layer(new Game2D::SceneNode());
			_sceneLayers[L] = layer.get();
			_sceneTree.attachChild(std::move(layer));
		}

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
		leftEscort ->setPosition(-80.f, 50.f);
		rightEscort->setPosition(80.f, 50.f);
		leftEscort->Velocity = sf::Vector2f(_playerSpeed, _scrollSpeed);
		rightEscort->Velocity = sf::Vector2f(_playerSpeed, _scrollSpeed);
		_player->attachChild(std::move(leftEscort));
		_player->attachChild(std::move(rightEscort));

	}

}