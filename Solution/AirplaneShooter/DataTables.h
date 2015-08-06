#pragma once

#include "Aircraft.h"

#include <Render\ResourceId.h>

#include <map>

namespace Shooter {

	struct AircraftData {
		int hitPoints;
		float speed;
		Game2D::ResourceId texture;
	};
	typedef std::map<Aircraft::Type, AircraftData> AircraftDataTable;
	AircraftDataTable initAircraftData();

}
