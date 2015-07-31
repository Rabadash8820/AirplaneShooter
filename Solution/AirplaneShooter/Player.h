#pragma once

#include <Input\InputManager.h>
#include <Input\Command.h>

#include <SFML\Window\Event.hpp>

#include <queue>

namespace Shooter {

	class Player : public Game2D::InputManager {
		// INTERFACE
	public:
		Player();
		virtual void handleRealtimeInput(std::queue<Game2D::Command>&) const;

		// HELPER FUNCTIONS
	private:
		virtual void handleKeyPress(const sf::Event::KeyEvent&, std::queue<Game2D::Command>&) const;
	};

}
