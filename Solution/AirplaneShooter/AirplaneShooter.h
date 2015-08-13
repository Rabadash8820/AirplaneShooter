#pragma once

#include "Player.h"
#include "Ids\TextureId.h"
#include "Ids\FontId.h"
#include "Ids\GuiId.h"

#include <Application.h>

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

namespace Shooter {

	class AirplaneShooter : public Game2D::Application {
		// ENCAPSULATED FIELDS
	private:
		sf::RenderWindow _window;
		ButtonTextureManager _buttonTextures;
		TextureManager _textures;
		FontManager _fonts;
		Player _player;
		sf::Text _statisticsText;
		sf::Time _statisticsUpdateTime;
		std::size_t _statisticsNumFrames;

		// INTERFACE
	public:
		AirplaneShooter();

		// HELPER FUNCTIONS
	private:
		virtual void drawCurrent();
		virtual void updateCurrent(sf::Time dt);
	};

}
