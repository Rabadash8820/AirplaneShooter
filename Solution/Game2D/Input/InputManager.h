#pragma once

#include "..\GAME2D_API.h"
#include "Command.h"
#include "ActionId.h"

#include <SFML\Window\Event.hpp>

#include <set>
#include <queue>
#include <map>

namespace Game2D {

	class GAME2D_API InputManager {
		// PRIVATE FIELDS
	protected:
		std::map<ActionId, std::set<sf::Keyboard::Key>> _keyBindings;
		std::map<ActionId, Command> _commandBindings;

		// INTERFACE
	public:
		InputManager() { }
		void handleEvent(const sf::Event&, std::queue<Command>&) const;
		void handleRealtimeInput(std::queue<Command>&) const;
		std::set<sf::Keyboard::Key> keysBoundTo(ActionId) const;
		void bindKey(sf::Keyboard::Key, ActionId);

		// HELPER FUNCTIONS
	protected:
		void bindCommand(const Command&, ActionId);

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
		virtual void handleOtherEvent(		  const sf::Event&,						   std::queue<Command>&) const { }
	private:
		void handleRealtimeKeyboard(std::queue<Command>&) const;
	protected:
		virtual void handleRealtimeMouse(std::queue<Command>&) const { }
		virtual void handleRealtimeJoystick(std::queue<Command>&) const { }
		virtual void handleOtherRealtime(std::queue<Command>&) const { }

	};

}
