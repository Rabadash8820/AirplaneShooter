#include "Aircraft.h"
#include "ResourceManager.h"
#include "Categories.h"

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Aircraft::Aircraft(Type t, const TextureManager<ResourceIDs::Texture>& textures) :
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
	switch (_type) {
	case EAGLE:
		return PlayerAircraft.getId();
	default:
		return EnemyAircraft.getId();
	}
}

// HELPER FUNCTIONS
ResourceIDs::Texture Aircraft::textureIdForType(Aircraft::Type t) {
	switch (t) {
	case Type::EAGLE:
		return ResourceIDs::Texture::EAGLE;
		break;
	case Type::RAPTOR:
	default:
		return ResourceIDs::Texture::RAPTOR;
		break;
	}
}
