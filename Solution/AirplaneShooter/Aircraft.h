#pragma once

#include "TextureIds.h"
#include <ResourceManager.h>
#include <Render\Entity.h>
#include <SFML/Graphics.hpp>
#include <memory>

namespace Shooter {

	class Aircraft : public Game2D::Entity {
		// TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
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
		virtual unsigned int getCategory() const;

		// HELPER FUNCTIONS
	private:
		ResourceIDs::Texture textureIdForType(Type);

	};

}