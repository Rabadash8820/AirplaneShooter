#pragma once

#include <Map.h>

#include "Aircraft.h"
#include "Ids\TextureId.h"
#include "Ids\FontId.h"

#include <Render\Entity.h>
#include <Render\ResourceManager.h>

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\System\Time.hpp>

#include <array>
#include <vector>

namespace Shooter {

	class DesertMap final : public Game2D::Map {
		// ABSTRACT DATA TYPES
	private:
		enum Layer {
			Background = 0,
			Ground,
			Air,
			LayerCount
		};
		struct SpawnPoint {
			SpawnPoint(Aircraft::Type, float, float);
			Aircraft::Type type;
			float x, y;
		};

		// ENCAPSULATED FIELDS
	private:
		const float BORDER_OFFSET = 40.f;
		const float BATTLEFIELD_OFFSET = 100.f;
		const float PLAYER_SPEED = 200.f;	// Pixels per sec

		sf::View _view;
		sf::IntRect _worldBounds;
		std::array<Game2D::SceneNode*, LayerCount> _sceneLayers;
		Aircraft* _player;
		sf::Vector2f _playerSpawn;
		sf::Vector2f _scrollVelocity;		// Pixels per sec
		std::vector<SpawnPoint> _spawnPoints;
		TextureManager _textures;
		FontManager _fonts;

		// INTERFACE
	public:
		DesertMap(sf::RenderWindow&);

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time);
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void loadResources();
		virtual void buildScene();
		void addEnemy(Aircraft::Type, float, float);
		void addEnemies();
		sf::FloatRect getBattlefieldBounds() const;
		void spawnEnemies();
		void adjustPlayer(sf::Time);

	};

}
