#pragma once

#include "ResourceHolder.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Shader.hpp>

namespace Game2D {

	template<typename Id>
	using TextureHolder = ResourceHolder<Id, sf::Texture>;
	template<typename Id>
	using FontHolder = ResourceHolder<Id, sf::Font>;
	template<typename Id>
	using SoundBufferHolder = ResourceHolder<Id, sf::SoundBuffer>;
	template<typename Id>
	using ShaderHolder = ResourceHolder<Id, sf::Shader>;

}