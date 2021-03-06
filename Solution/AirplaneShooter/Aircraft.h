#pragma once

#include "ResourceIds\Textures.h"

#include <Render\ResourceId.h>
#include <Render\ResourceManager.h>
#include <Render\Entity.h>
#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>

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
		Aircraft(Type, const Game2D::TextureManager&);
		float airSpeed;
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual Game2D::Category getCategory() const;

		// HELPER FUNCTIONS
	private:
		Game2D::ResourceId textureIdForType(Type);

	};

}
