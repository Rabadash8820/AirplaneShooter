#pragma once

#include "Command.h"
#include <SFML\Graphics.hpp>


namespace Game2D {


	struct InputBinding {
		// CONSTRUCTORS / DESTRUCTOR
	public:
		InputBinding() {}
		~InputBinding() {}

		// PROPERTIES
	public:
		sf::Keyboard::Key Key;
		Command Command;

	};

}
