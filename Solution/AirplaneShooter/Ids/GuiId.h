#pragma once

#include <Render\ResourceManager.h>
#include <GUI\Button.h>

#include <SFML\Graphics\Texture.hpp>

namespace Shooter {

	typedef Game2D::ResourceManager<sf::Texture, Game2D::GUI::Button::State> ButtonTextureManager;

}
