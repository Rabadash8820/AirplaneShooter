#pragma once

#include <States\State.h>
#include <States\StateManager.h>
#include <GUI.h>
#include <Input\CommandId.h>

#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Sprite.hpp>

#include <string>
#include <set>
#include <map>

namespace Shooter {

	class SettingsState : public Game2D::State {
		// ENCAPSULATED FIELDS
	private:
		sf::Sprite _background;
		Game2D::GUI::Container _guiContainer;
		std::map<Game2D::CommandId, Game2D::GUI::Button::Ptr> _bindingButtons;
		std::map<Game2D::CommandId, Game2D::GUI::Label::Ptr>  _bindingLabels;

		// INTERFACE
	public:
		SettingsState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

		// HELPER FUNCTIONS
	private:
		void packControl(Game2D::CommandId, float, const std::string&, Context);
		void updateLabels();
		void updateLabel(Game2D::CommandId, std::set<sf::Keyboard::Key>);

	};

}
