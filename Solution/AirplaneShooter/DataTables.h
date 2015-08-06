#pragma once

#include "Aircraft.h"
#include "ResourceIds\Textures.h"

#include <Render\ResourceId.h>

namespace Shooter {

	struct AircraftData {
		int hitPoints;
		float speed;
		Game2D::ResourceId texture;
	};
	static Aircraft::DataTable initAircraftData() {
		Aircraft::DataTable data;

		data[Aircraft::Type::EAGLE].hitPoints = 100;
		data[Aircraft::Type::EAGLE].speed = 200.f;
		data[Aircraft::Type::EAGLE].texture = Textures::Eagle;

		data[Aircraft::Type::RAPTOR].hitPoints = 100;
		data[Aircraft::Type::RAPTOR].speed = 80.f;
		data[Aircraft::Type::RAPTOR].texture = Textures::Raptor;

		return data;
	}

}
