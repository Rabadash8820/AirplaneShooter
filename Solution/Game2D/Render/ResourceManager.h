#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceId.h"
#include <map>
#include <memory>
#include <string>

namespace Game2D {

	template<typename Resource>
	class ResourceManager {
	private:
		// VARIABLES
		typedef std::unique_ptr<Resource> Ptr;
		std::map<unsigned int, Ptr> _resources;
		
	public:
		// CONSTRUCTORS / DESTRUCTOR
		ResourceManager();
		~ResourceManager();

		// FUNCTIONS
		void load(ResourceId, const std::string&);
		template<typename Param>
		void load(ResourceId, const std::string&, Param);
		Resource& get(ResourceId) const;
		Resource& operator[](ResourceId) const;
	};

	// Typedefs for specific ResourceManagers
	typedef ResourceManager<sf::Texture>	 TextureManager;
	typedef ResourceManager<sf::Font>		 FontManager;
	typedef ResourceManager<sf::SoundBuffer> SoundManager;
	typedef ResourceManager<sf::Shader>      ShaderManager;

#include "ResourceManager.inl"

}
