#include "AirplaneShooter.h"
#include "DesertMap.h"
#include <memory>

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	AirplaneShooter::AirplaneShooter() :
		Game(sf::seconds(1.f / 60.f), sf::VideoMode(640, 480), "Airplane Shooter")
	{
		std::unique_ptr<Game2D::Map> desert(new DesertMap(_window.getDefaultView()));
		this->setMap(std::move(desert));
	}
	AirplaneShooter::~AirplaneShooter() {}

}