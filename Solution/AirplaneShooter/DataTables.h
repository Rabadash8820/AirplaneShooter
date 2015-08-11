#pragma once

#include "Aircraft.h"
#include "ResourceIds\Textures.h"

#include <Render\ResourceId.h>

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
		Game2D::ResourceId texture;
		std::vector<Direction> directions;
	};

}
