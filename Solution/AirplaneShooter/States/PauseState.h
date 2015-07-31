#pragma once

#include <States\State.h>
#include <States\StateManager.h>

namespace Shooter {

	class PauseState : public Game2D::State {
	public:
		PauseState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();
	};

}
