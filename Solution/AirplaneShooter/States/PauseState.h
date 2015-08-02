#pragma once

#include <States\State.h>
#include <States\StateManager.h>

#include <SFML\Graphics\Text.hpp>

namespace Shooter {

	class PauseState : public Game2D::State {
		// ENCAPSULATED FIELDS
	private:
		sf::Text _pauseText;
		sf::Text _instructionText;

		// INTERFACE
	public:
		PauseState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();
	};

}
