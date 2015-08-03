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
		virtual void handleKeyPress(		  const sf::Event::KeyEvent&,			   std::queue<Command>&) const { }
		virtual void handleKeyRelease(		  const sf::Event::KeyEvent&,			   std::queue<Command>&) const { }
		virtual void handleMousePress(		  const sf::Event::MouseButtonEvent&,	   std::queue<Command>&) const { }
		virtual void handleMouseRelease(	  const sf::Event::MouseButtonEvent&,	   std::queue<Command>&) const { }
		virtual void handleMouseMove(		  const sf::Event::MouseMoveEvent&,		   std::queue<Command>&) const { }
		virtual void handleMouseScroll(		  const sf::Event::MouseWheelScrollEvent&, std::queue<Command>&) const { }
		virtual void handleJoystickPress(	  const sf::Event::JoystickButtonEvent&,   std::queue<Command>&) const { }
		virtual void handleJoystickRelease(	  const sf::Event::JoystickButtonEvent&,   std::queue<Command>&) const { }
		virtual void handleJoystickConnect(	  const sf::Event::JoystickConnectEvent&,  std::queue<Command>&) const { }
		virtual void handleJoystickDisconnect(const sf::Event::JoystickConnectEvent&,  std::queue<Command>&) const { }
		virtual void handleJoystickMove(      const sf::Event::JoystickMoveEvent&,     std::queue<Command>&) const { }
	};

}
