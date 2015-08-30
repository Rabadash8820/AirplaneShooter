#pragma once

#include <ResourceManager.h>

#include <SFML\Graphics\Texture.hpp>

namespace Shooter {

	enum class TextureId {
		Desert,
		
		Eagle,
		Raptor,
		Avenger,
		
		Bullet,
		Missile,
		
		TitleScreen,

		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,

	};

	typedef Game2D::ResourceManager<sf::Texture, TextureId> TextureManager;

}
