#pragma once

#include <Game.h>
#include <Category.h>

namespace Shooter {

	class AirplaneShooter : public Game2D::Game {
		// MEMBER VARIABLES / CONSTANTS
	private:
		Game2D::Category Nothing, PlayerAircraft, AlliedAircraft, EnemyAircraft;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		AirplaneShooter();
		~AirplaneShooter();

		// INITIALIZATION FUNCTIONS
		void initKeyBindings();
	};

}