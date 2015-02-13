#include "Aircraft.h"
#include <ResourceHolderTypes.h>

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	Aircraft::Aircraft(Type t, const Game2D::TextureHolder<Textures::ID>& textures) {
		_type = t;

		// Initialize the Aircraft's Sprite
		sf::FloatRect bounds = _sprite.getLocalBounds();
		_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
		_sprite.setTexture(textures[toTextureId(t)]);
	}
	Aircraft::~Aircraft() {}

	// FUNCTIONS
	Textures::ID Aircraft::toTextureId(Aircraft::Type t) {
		switch (t) {
		case EAGLE:
			return Textures::EAGLE;
			break;
		case RAPTOR:
		default:
			return Textures::RAPTOR;
			break;
		}
	}
	void Aircraft::renderCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(_sprite, states);
	}

}
