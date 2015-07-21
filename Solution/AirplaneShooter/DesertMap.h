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
		const float BORDER_OFFSET = 40.f;
		Game2D::TextureManager<ResourceIDs::Texture> _textures;
		const float PLAYER_SPEED = 200.f;	// Speeds in pixels/sec

		// INTERFACE
	public:
		DesertMap(sf::RenderWindow*);
		~DesertMap();

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time);
		virtual void loadResources();
		virtual void buildScene();
		virtual void handleEvent(const sf::Event&);
		void adjustPlayer(sf::Time);

	};

}
