#pragma once

#include "Command.h"

#include <SFML\Window\Keyboard.hpp>

namespace Game2D {
	
	class KeyBinding {
		// INTERFACE
	public:
		KeyBinding(sf::Keyboard::Key key, Command command) :
			command(command),
			key(key)
		{ }

		sf::Keyboard::Key key;
		Command command;

	};

}
