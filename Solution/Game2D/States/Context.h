#pragma once

#include "..\GAME2D_API.h"
#include "..\Render\ResourceManager.h"
#include "..\Input\InputManager.h"

#include <SFML\Graphics\RenderWindow.hpp>

namespace Game2D {

	struct Context {
		// CONSTRUCTOR
		Context(sf::RenderWindow& window, TextureManager& textures, FontManager& fonts, InputManager& input) {
			this->window = &window;
			this->textures = &textures;
			this->fonts = &fonts;
			this->input = &input;
		}

		// PROPERTIES
		sf::RenderWindow* window;
		TextureManager* textures;
		FontManager* fonts;
		InputManager* input;
	};

}
