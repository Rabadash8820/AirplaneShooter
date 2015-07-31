#pragma once

#include "..\GAME2D_API.h"
#include "KeyBinding.h"
#include "Command.h"

#include <SFML\Window\Event.hpp>

#include <vector>
#include <queue>

namespace Game2D {

	class GAME2D_API InputManager {
		// PRIVATE FIELDS
	protected:
		std::vector<KeyBinding> _keyBindings;

		// INTERFACE
	public:
		InputManager() { }
		virtual void handleEvent(const sf::Event&, std::queue<Command>&) const final;
		virtual void handleRealtimeInput(std::queue<Command>&) const = 0;

		// HELPER FUNCTIONS
	protected:
		virtual void handleKeyboardEvent(const sf::Event::KeyEvent&, std::queue<Command>&) const;
		virtual void handleMouseEvent(const sf::Event&, std::queue<Command>&) const;
		virtual void handleJoystickEvent(const sf::Event&, std::queue<Command>&) const;
	};

}
