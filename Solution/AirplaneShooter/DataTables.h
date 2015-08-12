#pragma once

#include "Aircraft.h"
#include "Ids\TextureId.h"

#include <vector>

namespace Shooter {

	struct Direction {
		Direction(float, float);
		float angle;
		float distance;
	};

	struct AircraftData {
		int hitPoints;
		float speed;
		TextureId texture;
		std::vector<Direction> directions;
	};

}
