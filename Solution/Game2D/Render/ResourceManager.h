#pragma once

#include "ResourceId.h"

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Shader.hpp>
#include <SFML\Audio\SoundBuffer.hpp>

#include <map>
#include <memory>
#include <string>

namespace Game2D {

	template<typename Resource>
	class ResourceManager {
	private:
		// VARIABLES
		typedef std::unique_ptr<Resource> Ptr;
		std::map<ResourceId, Ptr> _resources;
		
	public:
		// CONSTRUCTORS / DESTRUCTOR
		ResourceManager();

		// FUNCTIONS
		void load(const ResourceId&, const std::string&);
		template<typename Param>
		void load(const ResourceId&, const std::string&, Param);
		Resource& get(const ResourceId&) const;
		Resource& operator[](const ResourceId&) const;
	};

	// Typedefs for specific ResourceManagers
	typedef ResourceManager<sf::Texture>	 TextureManager;
	typedef ResourceManager<sf::Font>		 FontManager;
	typedef ResourceManager<sf::SoundBuffer> SoundManager;
	typedef ResourceManager<sf::Shader>      ShaderManager;

#include "ResourceManager.inl"

}
