#pragma once

#include <Application.h>

namespace Shooter {

	class AirplaneShooter : public Game2D::Application {
	public:
		AirplaneShooter();

	private:
		virtual void registerStates();
	};

}
