#pragma once

#include "Player.h"

#include <Render\ResourceManager.h>
#include <Application.h>

#include <SFML\Graphics\RenderWindow.hpp>

namespace Shooter {

	class AirplaneShooter : public Game2D::Application {
		// ENCAPSULATED FIELDS
	private:
		sf::RenderWindow _window;
		Game2D::TextureManager _textures;
		Game2D::FontManager _fonts;
		Player _player;

		// INTERFACE
	public:
		AirplaneShooter();

		// HELPER FUNCTIONS
	private:
		virtual void registerStates();
	};

}
