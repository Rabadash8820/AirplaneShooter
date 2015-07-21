#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <memory>
#include <string>

namespace Game2D {

	// BASE CLASS
	template<typename Id, typename Resource>
	class ResourceManager {
	private:
		// VARIABLES
		typedef std::unique_ptr<Resource> Ptr;
		std::map<Id, Ptr> _resources;


	public:
		// CONSTRUCTORS / DESTRUCTOR
		ResourceManager();
		~ResourceManager();

		// FUNCTIONS
		void load(Id, const std::string&);
		template<typename Param>
		void load(Id, const std::string&, Param);
		Resource& operator[](Id) const;
	};

	template<typename Id>
	using TextureManager = ResourceManager<Id, sf::Texture>;
	template<typename Id>
	using FontManager = ResourceManager<Id, sf::Font>;
	template<typename Id>
	using SoundManager = ResourceManager<Id, sf::SoundBuffer>;
	template<typename Id>
	using ShaderManager = ResourceManager<Id, sf::Shader>;

#include "ResourceManager.inl"

}