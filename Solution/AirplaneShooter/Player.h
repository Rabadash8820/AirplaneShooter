#pragma once

#include <Input\InputManager.h>
#include <Input\Command.h>
#include <Input\ActionId.h>

#include <SFML\Window\Event.hpp>

#include <queue>

namespace Shooter {

	class Player : public Game2D::InputManager {
		// ENCAPSULATED FIELDS
	private:
		Game2D::ActionId MoveLeft;
		Game2D::ActionId MoveRight;
		Game2D::ActionId MoveUp;
		Game2D::ActionId MoveDown;

		// INTERFACE
	public:
		Player();

		// HELPER FUNCTIONS
	private:
		virtual void handleKeyPress(const sf::Event::KeyEvent&, std::queue<Game2D::Command>&) const;
	};

}
