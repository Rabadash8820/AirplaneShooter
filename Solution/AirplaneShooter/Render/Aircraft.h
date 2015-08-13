#pragma once

#include "Entity.h"
#include "TextNode.h"
#include "..\Ids\FontId.h"
#include "..\Ids\TextureId.h"

#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>

#include <memory>
#include <map>

namespace Shooter {

	struct AircraftData;
	
	class Aircraft : public Entity {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
		enum class Type {
			Eagle,
			Raptor,
			Avenger,
		};
		typedef std::map<Type, AircraftData> DataTable;

		// ENCAPSULATED FIELDS
	private:
		static DataTable _dataTable;
		Type _type;
		sf::Sprite _sprite;
		TextNode* _hpDisplay;
		std::size_t _directionIndex;
		float _traveledDistance;

		// INTERFACE
	public:
		float airSpeed;
		Aircraft(Type, const TextureManager&, const FontManager&);
		virtual Game2D::Category getCategory() const; 

		// HELPER FUNCTIONS
	private:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time);
		void updateMovementDirections(sf::Time dt);
		float maxSpeed() const;

	};

}
