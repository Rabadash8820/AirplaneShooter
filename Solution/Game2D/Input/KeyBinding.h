#pragma once

#include "Command.h"
#include <SFML\Graphics.hpp>


namespace Game2D {
	
	class KeyBinding {
		// MEMBER VARIABLES
	private:
		Command _command;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		KeyBinding(sf::Keyboard::Key key, Command command) :
			_command(command),
			key(key)
		{ }
		~KeyBinding() { }

		// INTERFACE
	public:
		sf::Keyboard::Key key;
		Command getCommand() const {
			return _command;
		}

	};

}
