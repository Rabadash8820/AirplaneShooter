#pragma once

#include "BaseState.h"

#include <States\StateManager.h>
#include <GUI.h>

#include <SFML\Window\Event.hpp>
#include <SFML\System\Time.hpp>

#include <vector>

namespace Shooter {

	class MenuState : public BaseState {
		// ENCAPSULATED FIELDS
	private:
		const sf::Vector2f FIRST_BUTTON_POS = sf::Vector2f(100.f, 200.f);
		const sf::Vector2f BUTTON_OFFSET = sf::Vector2f(0.f, 50.f);
		sf::Sprite _background;
		Game2D::GUI::Container _guiContainer;
		
		// INTERFACE
	public:
		MenuState(Game2D::StateManager&);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

	};

}
