#pragma once

#include <Application.h>

namespace Shooter {

	class Game : public Game2D::Application {
		// CONSTRUCTORS / DESTRUCTOR
	public:
		Game();
		~Game();

		// INITIALIZATION FUNCTIONS
		void initKeyBindings();
		virtual void registerStates();
	};

}
