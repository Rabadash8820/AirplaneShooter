#pragma once

#include <States\State.h>
#include <States\StateManager.h>
#include <GUI.h>

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

namespace Shooter {

	class PauseState : public Game2D::State {
		// ENCAPSULATED FIELDS
	private:
		sf::Text _pauseText;
		sf::RectangleShape _background;
		Game2D::GUI::Container _guiContainer;

		// INTERFACE
	public:
		PauseState(Game2D::StateManager&);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();
	};

}
