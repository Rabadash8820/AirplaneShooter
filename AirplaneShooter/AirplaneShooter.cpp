#include "AirplaneShooter.h"
#include "DesertMap.h"
#include <memory>

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	AirplaneShooter::AirplaneShooter() :
		Game(sf::VideoMode(640, 480), "Airplane Shooter")
	{
		Game2D::Map::Ptr desert(new DesertMap(&_window));
		this->setMap(std::move(desert));
	}
	AirplaneShooter::~AirplaneShooter() {}

}