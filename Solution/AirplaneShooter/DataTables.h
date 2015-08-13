#pragma once

#include "Render\Aircraft.h"
#include "Ids\TextureId.h"

#include <vector>
#include <map>

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

	std::map<Aircraft::Type, AircraftData> initAircraftData();

}
