#pragma once

#include "ResourceIds.h"
#include <ResourceManager.h>
#include <Map/ScrollingMap.h>
#include <array>

namespace Shooter {

	class DesertMap final : public Game2D::ScrollingMap {
		// VARIABLES / CONSTANTS
	private:
		const short BACKGROUND = 0, GROUND = 1, AIR = 2;
		const float BOUNDARY_OFFSET = 150.f;
		Game2D::TextureManager<ResourceIDs::Texture> _textures;
		float _playerSpeed;	// Speeds in pixels/sec

		// CONSTRUCTORS / DESTRUCTOR
	public:
		DesertMap(sf::RenderWindow*);
		~DesertMap();

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time);
		virtual void loadResources();
		virtual void buildScene();
		std::string projectDirectory();

	};

}