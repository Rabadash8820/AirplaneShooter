#include "Aircraft.h"

#include "Categories.h"

#include <SFML\Graphics\Rect.hpp>

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
Category Aircraft::getCategory() const {
	// All Aircraft are SceneNodes
	Category c = SceneNode::getCategory();

	// Adjust the game Category of this Aircraft depending on its type
	switch (_type) {
	case Type::EAGLE:
		c |= Categories::PlayerAircraft;
		break;

	case Type::RAPTOR:
		c |= Categories::AlliedAircraft;
		break;

	default:
		c |= Categories::EnemyAircraft;
		break;
	}
	return c;
}

// HELPER FUNCTIONS
ResourceId Aircraft::textureIdForType(Aircraft::Type t) {
	switch (t) {
	case Type::EAGLE:
		return Textures::Eagle;
		break;
	case Type::RAPTOR:
	default:
		return Textures::Raptor;
		break;
	}
}
