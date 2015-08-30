#pragma once

#include "..\GAME2D_API.h"
#include "Command.h"
#include "CommandId.h"

#include <SFML\Window\Event.hpp>

#include <set>
#include <vector>
#include <queue>
#include <map>

namespace Game2D {

	class GAME2D_API InputManager {
		// PRIVATE FIELDS
	protected:
		std::map<CommandId, std::set<sf::Keyboard::Key>> _keyBindings;
		std::map<CommandId, std::set<sf::Keyboard::Key>> _defaultKeyBindings;
		std::map<CommandId, Command> _commandBindings;

		// INTERFACE
	public:
		InputManager() { }
		void handleEvent(const sf::Event&, std::queue<Command>&) const;
		void handleRealtimeInput(std::queue<Command>&) const;
		void bindKey(sf::Keyboard::Key, CommandId);
		std::set<sf::Keyboard::Key> boundKeys(CommandId) const;
		Command boundCommand(CommandId) const;
		virtual std::vector<CommandId> commands() const = 0;
		void resetDefaults();

		// HELPER FUNCTIONS
	protected:
		virtual bool isRealtime(CommandId) const = 0;
		void bindDefaultKey(sf::Keyboard::Key, CommandId);
		void bindCommand(const Command&, CommandId);

		virtual void handleKeyPress(		  const sf::Event::KeyEvent&,			   std::queue<Command>&) const;
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
		void handleRealtimeMouse(std::queue<Command>&) const { }
		void handleRealtimeJoystick(std::queue<Command>&) const { }
		void handleOtherRealtime(std::queue<Command>&) const { }

	};

}
