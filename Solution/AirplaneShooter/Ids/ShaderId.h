#pragma once

#include <Render\ResourceManager.h>

#include <SFML\Graphics\Shader.hpp>

namespace Shooter {

	enum class ShaderId {
		Derp,
	};

	typedef Game2D::ResourceManager<sf::Shader, ShaderId> ShaderManager;

}
