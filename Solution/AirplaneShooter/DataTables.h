#pragma once

#include "Render\Pickup.h"
#include "Render\Aircraft.h"
#include "Render\Projectile.h"
#include "Ids\TextureId.h"

#include <SFML\System\Time.hpp>

#include <vector>
#include <map>

namespace Shooter {

	//
	// AIRCRAFT DATA
	//
	struct Direction {
		Direction(float, float);
		float angle;
		float distance;
	};

	struct AircraftData {
		int hitPoints;
		float speed;
		sf::Time fireInterval;
		TextureId texture;
		std::vector<Direction> directions;
	};
	
	std::map<Aircraft::Type, AircraftData> initAircraftData();

	//
	// PROJECTILE DATA
	//
	struct ProjectileData {
		int	damage;
		float speed;
		TextureId texture;
	};

	std::map<Projectile::Type, ProjectileData> initProjectileData();

	//
	// PICKUP DATA
	//
	struct PickupData {
		TextureId texture;
	};

	std::map<Pickup::Type, PickupData> initPickupData();
	

}
