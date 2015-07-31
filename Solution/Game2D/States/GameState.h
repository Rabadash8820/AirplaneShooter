#pragma once

#include "../GAME2D_API.h"
#include "../Map/Map.h"
#include "../Input/Command.h"
#include "../Input/KeyBinding.h"
#include "StateManager.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

namespace Game2D {

	class GAME2D_API GameState : State {
		// PRIVATE MEMBERS
	protected:
		Map::Ptr _map;
		std::vector<KeyBinding> _keyBindings;

		// INTERFACE
	private:
		GameState(StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		void handleRealtimeInput();
		virtual bool update(sf::Time);
		virtual void draw();

	};

}
