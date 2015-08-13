#include "DataTables.h"

using namespace Shooter;
using namespace std;

Direction::Direction(float a, float d) {
	angle = a;
	distance = d;
}

namespace Shooter {

	map<Aircraft::Type, AircraftData> initAircraftData() {
		map<Aircraft::Type, AircraftData> data;

		data[Aircraft::Type::Eagle].hitPoints = 100;
		data[Aircraft::Type::Eagle].speed = 200.f;
		data[Aircraft::Type::Eagle].texture = TextureId::Eagle;

		data[Aircraft::Type::Raptor].hitPoints = 20;
		data[Aircraft::Type::Raptor].speed = 80.f;
		data[Aircraft::Type::Raptor].texture = TextureId::Raptor;
		data[Aircraft::Type::Raptor].directions.push_back(Direction(45, 80));
		data[Aircraft::Type::Raptor].directions.push_back(Direction(-45, 160));
		data[Aircraft::Type::Raptor].directions.push_back(Direction(45, 80));

		data[Aircraft::Type::Avenger].hitPoints = 40;
		data[Aircraft::Type::Avenger].speed = 50.f;
		data[Aircraft::Type::Avenger].texture = TextureId::Avenger;
		data[Aircraft::Type::Avenger].directions.push_back(Direction(45, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(0, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(-45, 100));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(0, 50));
		data[Aircraft::Type::Avenger].directions.push_back(Direction(45, 50));

		return data;
	}

	map<Projectile::Type, ProjectileData> initProjectileData() {
		map<Projectile::Type, ProjectileData> data;

		return data;
	}

	map<Pickup::Type, PickupData> initPickupData() {
		map<Pickup::Type, PickupData> data;

		return data;
	}

}
