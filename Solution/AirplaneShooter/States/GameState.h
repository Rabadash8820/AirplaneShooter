#pragma once

#include "BaseState.h"

#include "..\Player.h"

#include <Map.h>
#include <States\StateManager.h>

#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include <memory>
#include <vector>
#include <string>

namespace Shooter {

	class GameState : BaseState {
		// PRIVATE MEMBERS
	private:
		Game2D::Map::Ptr _map;
		Player& _player;

		// INTERFACE
	public:
		GameState(Game2D::StateManager&);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

	};

}
