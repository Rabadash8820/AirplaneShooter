#include "DataTables.h"

#include "Categories.h"

using namespace Shooter;
using namespace std;
using namespace sf;

Direction::Direction(float a, float d) {
	angle = a;
	distance = d;
}

namespace Shooter {

	map<Aircraft::Type, AircraftData> initAircraftData() {
		map<Aircraft::Type, AircraftData> data;

		data[Aircraft::Type::Eagle].category = Categories::PlayerAircraft;
		data[Aircraft::Type::Eagle].hitPoints = 100;
		data[Aircraft::Type::Eagle].speed = 200.f;
		data[Aircraft::Type::Eagle].texture = TextureId::Eagle;
		data[Aircraft::Type::Eagle].fireInterval = sf::seconds(1);

		data[Aircraft::Type::Raptor].category = Categories::EnemyAircraft;
		data[Aircraft::Type::Raptor].hitPoints = 20;
		data[Aircraft::Type::Raptor].speed = 80.f;
		data[Aircraft::Type::Raptor].texture = TextureId::Raptor;
		data[Aircraft::Type::Raptor].directions.push_back(Direction(45, 80));
		data[Aircraft::Type::Raptor].directions.push_back(Direction(-45, 160));
		data[Aircraft::Type::Raptor].directions.push_back(Direction(45, 80));
		data[Aircraft::Type::Raptor].fireInterval = Time::Zero;

		data[Aircraft::Type::Avenger].category = Categories::EnemyAircraft;
		data[Aircraft::Type::Avenger].hitPoints = 40;
		data[Aircraft::Type::Avenger].speed = 50.f;
		data[Aircraft::Type::Avenger].texture = TextureId::Avenger;
		data[Aircraft::Type::Avenger].directions.push_back(Direction(45, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(0, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(-45, 100));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(0, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(45, 50));
		data[Aircraft::Type::Avenger].fireInterval = seconds(2);

		return data;
	}

	map<Projectile::Type, ProjectileData> initProjectileData() {
		map<Projectile::Type, ProjectileData> data;

		data[Projectile::Type::AlliedBullet].damage = 10;
		data[Projectile::Type::AlliedBullet].speed = 300.f;
		data[Projectile::Type::AlliedBullet].texture = TextureId::Bullet;

		data[Projectile::Type::EnemyBullet].damage = 10;
		data[Projectile::Type::EnemyBullet].speed = 300.f;
		data[Projectile::Type::EnemyBullet].texture = TextureId::Bullet;

		data[Projectile::Type::Missile].damage = 200;
		data[Projectile::Type::Missile].speed = 150.f;
		data[Projectile::Type::Missile].texture = TextureId::Missile;

		return data;
	}

	map<Pickup::Type, PickupData> initPickupData() {
		map<Pickup::Type, PickupData> data;

		data[Pickup::Type::HealthRefill].texture = TextureId::HealthRefill;
		data[Pickup::Type::HealthRefill].action  = [](Aircraft& a) { a.heal(25); };

		data[Pickup::Type::MissileRefill].texture = TextureId::MissileRefill;
		data[Pickup::Type::MissileRefill].action  = [](Aircraft& a) { a.collectMissiles(3); };

		data[Pickup::Type::FireSpread].texture = TextureId::FireSpread;
		data[Pickup::Type::FireSpread].action  = [](Aircraft& a) { a.increaseSpread(); };

		data[Pickup::Type::FireRate].texture = TextureId::FireRate;
		data[Pickup::Type::FireRate].action  = [](Aircraft& a) { a.increaseFireRate(); };

		return data;
	}

}
