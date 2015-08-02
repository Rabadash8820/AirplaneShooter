#pragma once

#include <Render\ResourceManager.h>
#include <Map/ScrollingMap.h>
#include <array>

namespace Shooter {

	class DesertMap final : public Game2D::ScrollingMap {
		// VARIABLES / CONSTANTS
	private:
		const short BACKGROUND = 0, GROUND = 1, AIR = 2;
		const float BORDER_OFFSET = 40.f;
		const float PLAYER_SPEED = 200.f;	// Speeds in pixels/sec

		// INTERFACE
	public:
		DesertMap(sf::RenderWindow*);

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time);
		virtual void loadResources();
		virtual void buildScene();
		void adjustPlayer(sf::Time);

	};

}
