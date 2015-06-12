#pragma once

#include <Input/Categories.h>

namespace Shooter {

	struct Categories : Game2D::Categories {
	public:
		unsigned int PlayerAircraft() { return 1 << 1; }
		unsigned int AlliedAircraft() { return 1 << 2; }
		unsigned int EnemyAircraft()  { return 1 << 3; }
	};

}