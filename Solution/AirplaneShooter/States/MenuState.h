#pragma once

#include <States\State.h>
#include <States\StateManager.h>

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Event.hpp>
#include <SFML\System\Time.hpp>

#include <vector>

namespace Shooter {

	class MenuState : public Game2D::State {
		// ABSTRACT DATA TYPES
	private:
		enum Options {
			Play,
			Exit,
		};

		// ENCAPSULATED FIELDS
	private:
		sf::Sprite _background;
		std::vector<sf::Text> _options;
		std::size_t _currentOption;
		
		// INTERFACE
	public:
		MenuState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

		// HELPER FUNCTIONS
	private:
		void updateOptionText();
		void changeState();

	};

}
