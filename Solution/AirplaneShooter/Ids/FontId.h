#pragma once

#include <ResourceManager.h>

#include <SFML\Graphics\Font.hpp>

namespace Shooter {

	enum class FontId {
		Main,
	};

	typedef Game2D::ResourceManager<sf::Font, FontId> FontManager;

}
