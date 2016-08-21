#include "Aircraft.h"
#include "Categories.h"
#include <Render\ResourceManager.h>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Aircraft::Aircraft(Type t, const TextureManager& textures) :
	_sprite(textures[textureIdForType(t)])

{
	_type = t;
	airSpeed = 0;

	// Initialize the Aircraft's Sprite
	FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

// INTERFACE FUNCTIONS
void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
unsigned int Aircraft::getCategory() const {
	// All Aircraft are SceneNodes
	unsigned int id = 1;

	// Adjust the game Category of this Aircraft depending on its type
	switch (_type) {
	case Type::EAGLE:
		id |= PlayerAircraft.getId();
		break;
	case Type::RAPTOR:
		id |= AlliedAircraft.getId();
		break;
	default:
		id |= EnemyAircraft.getId();
		break;
	}
	return id;
}

// HELPER FUNCTIONS
ResourceId Aircraft::textureIdForType(Aircraft::Type t) {
	switch (t) {
	case Type::EAGLE:
		return Textures::EAGLE;
		break;
	case Type::RAPTOR:
	default:
		return Textures::RAPTOR;
		break;
	}
}
