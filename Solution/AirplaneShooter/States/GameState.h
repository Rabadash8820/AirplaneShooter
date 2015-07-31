#pragma once

#include "..\Player.h"

#include <Map\Map.h>
#include <States\StateManager.h>
#include <States\State.h>

#include <SFML\Graphics.hpp>

#include <memory>
#include <vector>
#include <string>

namespace Shooter {

	class GameState : Game2D::State {
		// PRIVATE MEMBERS
	protected:
		Game2D::Map::Ptr _map;
		Player& _player;

		// INTERFACE
	private:
		GameState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

	};

}
