#pragma once

#include "ResourceIds.h"
#include <ResourceManager.h>
#include <ScrollingMap.h>
#include <array>

namespace Shooter {

	class DesertMap : public Game2D::ScrollingMap {
		// VARIABLES / CONSTANTS
	private:
		const short BACKGROUND = 0, GROUND = 1, AIR = 2;
		const float BOUNDARY_OFFSET = 150.f;
		Game2D::TextureManager<ResourceIDs::Texture> _textures;
		sf::Vector2f _playerVelocity;			// Speeds in pixels/sec

		// CONSTRUCTORS / DESTRUCTOR
	public:
		DesertMap(sf::RenderWindow*);
		~DesertMap();

		// HELPER FUNCTIONS
	private:
		virtual void postScrollUpdate(sf::Time);
		virtual void loadResources();
		virtual void buildScene();

	};

}