#include "Aircraft.h"

#include "Categories.h"
#include "DataTables.h"
#include "ResourceIds\Fonts.h"
#include "ResourceIds\Textures.h"

#include <Utility.h>

#include <SFML\Graphics\Rect.hpp>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

Aircraft::DataTable Aircraft::_dataTable = initAircraftData();

// INTERFACE
Aircraft::Aircraft(Type t, const TextureManager& textures, const FontManager& fonts) :
	Entity(_dataTable[t].hitPoints),
	_sprite(textures[textureIdForType(t)]),
	_type(t)
{
	// Define the TextNode with the Aircraft's health
	TextNode::Ptr health(new TextNode(fonts[Fonts::Main], ""));
	_hpDisplay = health.get();
	_hpDisplay->setPosition(0.f, 50.f);
	attachChild(std::move(health));

	// Initialize the Aircraft's Sprite
	FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}
Category Aircraft::getCategory() const {
	// All Aircraft are SceneNodes
	Category c = SceneNode::getCategory();

	// Adjust the game Category of this Aircraft depending on its type
	switch (_type) {
	case Type::EAGLE:
		return c | Categories::PlayerAircraft;
	case Type::RAPTOR:
		return c | Categories::AlliedAircraft;
	default:
		return c | Categories::EnemyAircraft;
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
void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
void Aircraft::updateCurrent(sf::Time dt) {
	Entity::updateCurrent(dt);

	_hpDisplay->setString(Utility::toString(getHitPoints()) + " HP");
	_hpDisplay->setRotation(getRotation());
}
