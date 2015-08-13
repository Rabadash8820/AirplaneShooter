#pragma once

#include "Render\Aircraft.h"

#include <Input\InputManager.h>
#include <Input\Command.h>
#include <Input\CommandId.h>

#include <SFML\Window\Event.hpp>
#include <SFML\System\Time.hpp>

#include <queue>
#include <vector>
#include <string>
#include <functional>

namespace Shooter {

	class Player : public Game2D::InputManager {

		// ENCAPSULATED FIELDS
	private:
		Game2D::CommandId MoveLeft;
		Game2D::CommandId MoveRight;
		Game2D::CommandId MoveUp;
		Game2D::CommandId MoveDown;
		Game2D::CommandId FireBullets;
		Game2D::CommandId LaunchMissile;

		// INTERFACE
	public:
		Player();
		std::vector<Game2D::CommandId> commands() const;

		// HELPER FUNCTIONS
	private:
		virtual void handleKeyPress(const sf::Event::KeyEvent&, std::queue<Game2D::Command>&) const;
	};

}
