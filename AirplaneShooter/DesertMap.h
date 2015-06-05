#pragma once

#include "ResourceIds.h"
#include <ResourceManager.h>
#include <ScrollingMap.h>
#include <array>

namespace Shooter {

	class DesertMap : public Game2D::ScrollingMap {
		// TYPES
	private:
		enum Layer {
			BACKGROUND,
			GROUND,
			AIR,
		};

		// VARIABLES / CONSTANTS
	private:
		const float BOUNDARY_OFFSET = 150.f;
		sf::FloatRect _worldBounds;
		Game2D::TextureManager<ResourceIDs::Texture> _textures;
		float _playerSpeed;			// Speeds in pixels/sec
		const float _scrollSpeed = 10.f;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		DesertMap(sf::View);
		~DesertMap();

		// HELPER FUNCTIONS
	private:
		virtual void postScrollUpdate(sf::Time);
		virtual void loadResources();
		virtual void buildScene();

	};

}