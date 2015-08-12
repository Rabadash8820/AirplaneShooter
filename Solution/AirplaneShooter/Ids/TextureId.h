#pragma once

#include <Render\ResourceManager.h>

#include <SFML\Graphics\Texture.hpp>

namespace Shooter {

	enum class TextureId {
		Desert,
		Eagle,
		Raptor,
		Missile,
		TitleScreen,
	};

	typedef Game2D::ResourceManager<sf::Texture, TextureId> TextureManager;

}
