#pragma once

#include "Entity.h"
#include <vector>

namespace Game2D {

	class World : public sf::NonCopyable {
	private:
		// VARIABLES / CONSTANTS
		sf::RenderWindow& _window;
		sf::View _view;
		sf::FloatRect _worldBounds;

		SceneNode _sceneTree;
		
		Entity* _player;
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