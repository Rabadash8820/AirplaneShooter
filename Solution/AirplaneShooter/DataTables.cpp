#include "DataTables.h"

#include "ResourceIds\Textures.h"

using namespace Game2D;
using namespace Shooter;
using namespace std;

AircraftDataTable initAircraftData() {
	AircraftDataTable data;

	data[Aircraft::Type::EAGLE].hitPoints = 100;
	data[Aircraft::Type::EAGLE].speed = 200.f;
	data[Aircraft::Type::EAGLE].texture = Textures::Eagle;

	data[Aircraft::Type::RAPTOR].hitPoints = 100;
	data[Aircraft::Type::RAPTOR].speed = 80.f;
	data[Aircraft::Type::RAPTOR].texture = Textures::Raptor;

	return data;
}
