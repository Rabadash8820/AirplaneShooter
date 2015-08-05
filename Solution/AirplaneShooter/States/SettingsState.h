#pragma once

#include <States\State.h>
#include <States\StateManager.h>
#include <GUI.h>

#include <SFML\Window\Event.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Sprite.hpp>

#include <string>
#include <array>

namespace Shooter {

	class SettingsState : public Game2D::State {
		// ENCAPSULATED FIELDS
	private:
		sf::Sprite _background;
		Game2D::GUI::Container _guiContainer;
		std::array<Game2D::GUI::Button::Ptr, 5> _bindingButtons;
		std::array<Game2D::GUI::Label::Ptr, 5>  _bindingLabels;

		// INTERFACE
	public:
		SettingsState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

		// HELPER FUNCTIONS
	private:
		void updateLabels();
		void addButtonLabel(float, const std::string&, Context);

	};

}
