#pragma once

#include "ResourceIds\Textures.h"

#include <Render\ResourceId.h>
#include <Render\ResourceManager.h>
#include <Render\Entity.h>
#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>

#include <memory>

namespace std {
	template<typename Key, typename Val>
	class map<Key, Val>;
}

namespace Shooter {

	class Aircraft : public Game2D::Entity {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
		enum class Type {
			EAGLE,
			RAPTOR,
		};

		// ENCAPSULATED FIELDS
	private:
		Type _type;
		sf::Sprite _sprite;
		static AircraftDataTable _dataTable;

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
