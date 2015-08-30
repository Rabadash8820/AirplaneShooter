#pragma once

#include "Entity.h"
#include "TextNode.h"
#include "Projectile.h"
#include "..\Ids\FontId.h"
#include "..\Ids\TextureId.h"

#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>

#include <memory>
#include <map>
#include <queue>

namespace Shooter {

	struct AircraftData;
	
	class Aircraft : public Entity {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
		enum class Type {
			Eagle,
			Raptor,
			Avenger,
		};
		typedef std::map<Type, AircraftData> DataTable;

		// ENCAPSULATED FIELDS
	private:
		static DataTable _dataTable;
		Type _type;
		sf::Sprite _sprite;
		TextNode* _hpDisplay;
		std::size_t _directionIndex;
		float _traveledDistance;
		bool _isFiringBullets;
		bool _isLaunchingMissile;
		sf::Time _cooldownTime;
		Game2D::Command _fireBulletCommand;
		Game2D::Command _launchMissileCommand;
		int _fireRateLevel;
		int _fireSpreadLevel;
		unsigned int _missileAmmo;
		const int MAX_FIRE_RATE = 10;
		const int MAX_FIRE_SPREAD = 3;

		// INTERFACE
	public:
		float airSpeed;
		Aircraft(Type, const TextureManager&, const FontManager&);
		float getMaxSpeed() const;
		void fire();
		void launchMissile();
		void collectMissiles(unsigned int);
		void increaseSpread();
		void increaseFireRate();

		// HELPER FUNCTIONS
	private:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time, std::queue<Game2D::Command>&);
		void updateMovementDirections(sf::Time);
		bool isAllied() const;
		void launchProjectiles(sf::Time, std::queue<Game2D::Command>&);
		void launchBullets(Game2D::SceneNode&, const TextureManager&) const;
		void launchProjectile(Game2D::SceneNode&, Projectile::Type, float, float, const TextureManager&) const;
	};

}
