#include "Aircraft.h"

#include "..\Categories.h"
#include "..\DataTables.h"

#include <Utility.h>

#include <SFML\Graphics\Rect.hpp>

#include <cmath>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

Aircraft::DataTable Aircraft::_dataTable = initAircraftData();

// INTERFACE
Aircraft::Aircraft(Type t, const TextureManager& textures, const FontManager& fonts) :
	_type(t),
	Entity(_dataTable[_type].hitPoints),
	_sprite(textures[_dataTable[_type].texture]),
	_traveledDistance(0),
	_directionIndex(0)
{
	// Define the TextNode with the Aircraft's health
	TextNode::Ptr health(new TextNode(fonts[FontId::Main], ""));
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
	case Type::Eagle:
		return c | Categories::PlayerAircraft;
	default:
		return c | Categories::EnemyAircraft;
	}
	return c;
}

// HELPER FUNCTIONS
void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
void Aircraft::updateCurrent(Time dt) {
	updateMovementDirections(dt);
	Entity::updateCurrent(dt);

	_hpDisplay->setString(Utility::toString(getHitPoints()) + " HP");
	_hpDisplay->setRotation(getRotation());
}
void Aircraft::updateMovementDirections(Time dt) {
	// If this Aircraft's type has no movement directions then just return (it will fly straight down)
	const std::vector<Direction>& directions = _dataTable[_type].directions;
	if (directions.empty()) return;

	// Adjust the current Direction index based on the Aircraft's current distance traveled
	float distance = directions[_directionIndex].distance;
	if (_traveledDistance > distance) {
		_directionIndex = (_directionIndex + 1) % directions.size();
		_traveledDistance = 0.f;
	}

	// Adjust the Aircraft's velocity vector and distance traveled
	float radians = Utility::toRadians(directions[_directionIndex].angle);
	float speed = maxSpeed();
	Vector2f vel(speed * sinf(radians), speed * cosf(radians));
	velocity = vel;
	_traveledDistance += (speed * dt.asSeconds());
}
float Aircraft::maxSpeed() const {
	return _dataTable[_type].speed;
}
