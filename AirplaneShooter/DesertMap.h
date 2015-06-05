#pragma once

#include "ResourceIds.h"
#include <ResourceManager.h>
#include <ScrollingMap.h>
#include <array>

namespace Shooter {

	class DesertMap : public Game2D::ScrollingMap {
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

		Game2D::TextureManager<ResourceIDs::Texture> _textures;

		sf::Vector2f _playerSpawn;
		float _playerSpeed = 40.f;			// Speeds in pixels/sec
		const float _scrollSpeed = 10.f;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		DesertMap(sf::View);
		~DesertMap();

	private:
		// HELPER FUNCTIONS
		virtual void postScrollUpdate(sf::Time);
		virtual void loadResources();
		virtual void buildScene();

	};

}