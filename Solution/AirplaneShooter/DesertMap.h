#pragma once

#include <Map.h>

#include <Render\Entity.h>
#include <Render\ResourceManager.h>

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\System\Time.hpp>

namespace Shooter {

	class DesertMap final : public Game2D::Map {
		// ENCAPSULATED FIELDS
	private:
		const short BACKGROUND = 0, GROUND = 1, AIR = 2;
		const float BORDER_OFFSET = 40.f;
		const float PLAYER_SPEED = 200.f;	// Pixels per sec
		sf::View _view;
		sf::IntRect _worldBounds;
		size_t _numLayers;
		std::vector<Game2D::SceneNode*> _sceneLayers;
		Game2D::Entity* _player;
		sf::Vector2f _playerSpawn;
		sf::Vector2f _scrollVelocity;		// Pixels per sec

		// INTERFACE
	public:
		DesertMap(sf::RenderWindow&);

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time);
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void loadResources();
		virtual void buildScene();
		void adjustPlayer(sf::Time);

	};

}
