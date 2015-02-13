#pragma once

#include "ResourceIds.h"
#include <Map.h>
#include <array>

namespace Shooter {

	class DesertMap : public Game2D::Map {
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
		sf::FloatRect _worldBounds;

		static const short NUM_LAYERS = 3;

		Game2D::TextureHolder<Textures::ID> _textures;

		sf::Vector2f _playerSpawn;
		float _playerSpeed = 40.f;			// Speeds in pixels/sec
		const float _scrollSpeed = 10.f;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit DesertMap(sf::RenderWindow&, size_t);
		~DesertMap();

	private:
		// HELPER FUNCTIONS
		virtual void baseUpdates(sf::Time);
		virtual void loadResources();
		virtual void buildScene();

	};

}