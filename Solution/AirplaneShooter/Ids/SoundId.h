#pragma once

#include <Render\ResourceManager.h>

#include <SFML\Audio\SoundBuffer.hpp>

namespace Shooter {

	enum class SoundId {
		Derp,
	};

	typedef Game2D::ResourceManager<sf::SoundBuffer, SoundId> SoundManager;
	
}
