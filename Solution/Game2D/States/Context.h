#pragma once

#include "..\GAME2D_API.h"
#include "..\Render\ResourceManager.h"
#include "..\Input\InputManager.h"

#include <SFML\Graphics\RenderWindow.hpp>

namespace Game2D {

	struct Context {
		// CONSTRUCTOR
		Context(sf::RenderWindow& window, InputManager& input) {
			this->window = &window;
			this->input = &input;
		}

		// PROPERTIES
		sf::RenderWindow* window;
		InputManager* input;
	};

}
