#pragma once

#include <States\State.h>
#include <States\StateManager.h>

#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\System\Time.hpp>

namespace Shooter {

	class TitleState : public Game2D::State {
		// PRIVATE MEMBERS
	private:
		sf::Sprite _backgroundSprite;
		sf::Text _text;
		bool _showText;
		sf::Time _effectTime;
		const sf::Time TEXT_EFFECT_TIME = sf::seconds(0.5f);

		// INTERFACE
	public:
		TitleState(Game2D::StateManager&, Context);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();
	};

}
