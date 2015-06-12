#include "Aircraft.h"
#include "ResourceManager.h"
#include "Categories.h"

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
Aircraft::Aircraft(Type t, const TextureManager<ResourceIDs::Texture>& textures) :
	Entity(unique_ptr<Game2D::Categories>(new Shooter::Categories())),
	_sprite(textures[textureIdForType(t)])

{
	_type = t;

	// Initialize the Aircraft's Sprite
	FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}
Aircraft::~Aircraft() {}

// INTERFACE FUNCTIONS
void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
unsigned int Aircraft::getCategory() const {
	Shooter::Categories* c = reinterpret_cast<Shooter::Categories*>(_categories.get());
	switch (_type) {
	case EAGLE:
		return c->PlayerAircraft();
	default:
		return c->EnemyAircraft();
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