#pragma once

#include "TextureIds.h"
#include <ResourceHolderTypes.h>
#include <Entity.h>
#include <SFML/Graphics.hpp>

namespace Shooter {

	class Aircraft : public Game2D::Entity {
	public:
		// TYPES
		enum Type {
			EAGLE,
			RAPTOR,
		};

	private:
		// VARIABLES
		Type _type;
		sf::Sprite _sprite;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit Aircraft(Type, const Game2D::TextureHolder<Textures::ID>&);
		~Aircraft();

		// FUNCTIONS
		virtual void renderCurrent(sf::RenderTarget&, sf::RenderStates) const;
		Textures::ID toTextureId(Type);

	};

}