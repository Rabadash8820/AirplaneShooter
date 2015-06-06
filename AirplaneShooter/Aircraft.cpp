#include "Aircraft.h"
#include "ResourceManager.h"

using namespace sf;
using namespace Game2D;

namespace Shooter {

	// CONSTRUCTORS / DESTRUCTOR
	Aircraft::Aircraft(Type t, const TextureManager<ResourceIDs::Texture>& textures)
		: _sprite(textures[textureIdForType(t)])
	{
		_type = t;

		// Initialize the Aircraft's Sprite
		FloatRect bounds = _sprite.getLocalBounds();
		_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}
	Aircraft::~Aircraft() {}

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
	void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
		target.draw(this->_sprite, states);
	}

}
