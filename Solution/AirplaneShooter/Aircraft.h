#pragma once

#include "TextureIds.h"
#include <ResourceManager.h>
#include <Render\Entity.h>
#include <SFML\Graphics.hpp>
#include <memory>

namespace Shooter {

	class Aircraft : public Game2D::Entity {
		// AIRCRAFT TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
		enum class Type {
			EAGLE,
			RAPTOR,
		};

		// VARIABLES
	private:
		Type _type;
		sf::Sprite _sprite;

		// INTERFACE
	public:
		Aircraft(Type, const Game2D::TextureManager<ResourceIDs::Texture>&);
		float airSpeed;
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual unsigned int getCategory() const;

		// HELPER FUNCTIONS
	private:
		ResourceIDs::Texture textureIdForType(Type);

	};

}
