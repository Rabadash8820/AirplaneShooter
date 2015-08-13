#include "Categories.h"

using namespace Game2D;

namespace Shooter {

	namespace Categories {

		Category PlayerAircraft,
			AlliedAircraft,
			EnemyAircraft,
			Pickup,
			AlliedProjectile,
			EnemyProjectile,
			Aircraft({ PlayerAircraft, AlliedAircraft, EnemyAircraft }),
			Projectile({ AlliedProjectile, EnemyProjectile });

	}

}
