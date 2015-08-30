#include "Pickup.h"

#include "..\DataTables.h"
#include "..\Categories.h"

#include <Utility.h>

using namespace Shooter;
using namespace Game2D;
using namespace sf;

Pickup::DataTable Pickup::_dataTable = initPickupData();

// INTERFACE
Pickup::Pickup(Type type, const TextureManager& textures) :
	Entity(1),
	_type(type),
	_sprite(textures[_dataTable[type].texture])
{
	Utility::centerOrigin(_sprite);
}
Category Pickup::getCaregory() const {
	return Categories::Pickup;
}
FloatRect Pickup::getBoundingRect() const {
	return getWorldTransform().transformRect(_sprite.getGlobalBounds());
}
void Pickup::apply(Aircraft& player) const {
	_dataTable[_type].action(player);
}