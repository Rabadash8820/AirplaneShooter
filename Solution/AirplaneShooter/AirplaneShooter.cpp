#include "AirplaneShooter.h"
#include "DesertMap.h"
#include <memory>

using namespace Shooter;
using namespace Game2D;
using namespace sf;

// CONSTRUCTORS / DESTRUCTOR
AirplaneShooter::AirplaneShooter() :
	Game(VideoMode(640, 480), "Airplane Shooter")
{
	Map::Ptr desert(new DesertMap(&_window));
	this->setMap(std::move(desert));
}
AirplaneShooter::~AirplaneShooter() {}