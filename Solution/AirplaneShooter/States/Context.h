#pragma once

#include "..\Ids\TextureId.h"
#include "..\Ids\FontId.h"
#include "..\Ids\GuiId.h"
#include "..\Player.h"

#include <States\Context.h>

#include <SFML\Graphics\RenderWindow.hpp>

namespace Shooter {

	struct Context : public Game2D::Context {
		// CONSTRUCTOR
		Context(
			sf::RenderWindow& window,
			ButtonTextureManager& buttonTextures,
			TextureManager& textures,
			FontManager& fonts,
			Player& player)
		: Game2D::Context(window, player)
		{
			this->buttonTextures = &buttonTextures;
			this->textures = &textures;
			this->fonts = &fonts;
		}

		// PROPERTIES
		ButtonTextureManager* buttonTextures;
		TextureManager*		  textures;
		FontManager*		  fonts;
	};

}
