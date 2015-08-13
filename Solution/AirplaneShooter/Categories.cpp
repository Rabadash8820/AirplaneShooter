#include "Categories.h"

using namespace Game2D;

namespace Shooter {

	namespace Categories {

		Category PlayerAircraft,
			AlliedAircraft,
			EnemyAircraft,
			Aircraft({ PlayerAircraft, AlliedAircraft, EnemyAircraft }),

			Pickup,

			AlliedProjectile,
			EnemyProjectile,
			Projectile({ AlliedProjectile, EnemyProjectile }),

			AirSceneLayer;

	}

}
