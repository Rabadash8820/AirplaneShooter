#pragma once

#include "TextureIds.h"
#include <ResourceManager.h>
#include <Entity.h>
#include <SFML/Graphics.hpp>

namespace Shooter {

	class Aircraft : public Game2D::Entity {
		// TYPES
	public:
		enum Type {
			EAGLE,
			RAPTOR,
		};

		// VARIABLES
	private:
		Type _type;
		sf::Sprite _sprite;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Aircraft(Type, const Game2D::TextureManager<ResourceIDs::Texture>&);
		~Aircraft();

		// INTERFACE FUNCTIONS
	public:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;

		// HELPER FUNCTIONS
	private:
		ResourceIDs::Texture textureIdForType(Type);

	};

}