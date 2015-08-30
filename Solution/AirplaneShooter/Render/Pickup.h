#pragma once

#include "Entity.h"
#include "..\Ids\TextureId.h"

#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Rect.hpp>

#include <map>

namespace Shooter {

	struct PickupData;
	class Aircraft;

	class Pickup : public Entity {
		// ABSTRACT DATA TYPES
	public:
		enum class Type {
			HealthRefill,
			MissileRefill,
			FireSpread,
			FireRate,
		};
		typedef std::map<Type, PickupData> DataTable;

		// ENCAPSULATED FIELDS
	private:
		Type _type;
		sf::Sprite _sprite;
		static DataTable _dataTable;

		// INTERFACE
	public:
		Pickup(Type, const TextureManager&);
		virtual Game2D::Category getCaregory() const;
		virtual sf::FloatRect getBoundingRect() const;
		void apply(Aircraft&) const;

	};

}
