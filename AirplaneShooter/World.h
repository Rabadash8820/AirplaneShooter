#pragma once

#include "Aircraft.h"
#include "SceneNode.h"
#include <array>

namespace Shooter {

	class World : public sf::NonCopyable {
	private:
		// TYPES
		enum Layer {
			BACKGROUND,
			GROUND,
			AIR,
		};

		// VARIABLES / CONSTANTS
		const float WORLD_HEIGHT = 2000.f;
		const float BOUNDARY_OFFSET = 150.f;
		sf::RenderWindow& _window;
		sf::View _view;
		sf::FloatRect _worldBounds;

		Game2D::SceneNode _sceneGraph;
		static const short NUM_LAYERS = 3;
		std::array<Game2D::SceneNode*, NUM_LAYERS> _sceneLayers;

		Game2D::TextureManager<Textures::ID> _textures;

		Game2D::Entity* _player;
		sf::Vector2f _playerSpawn;
		float _playerSpeed = 40.f;			// Speeds in pixels/sec
		const float _scrollSpeed = 10.f;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit World(sf::RenderWindow& w);
		~World();

		// INTERFACE FUNCTIONS
		void update(sf::Time);
		void render();

	private:
		// HELPER FUNCTIONS
		void loadTextures();
		void buildScence();

	};

}