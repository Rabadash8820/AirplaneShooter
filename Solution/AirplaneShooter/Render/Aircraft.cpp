#include "Aircraft.h"

#include "..\Categories.h"
#include "..\DataTables.h"
#include "Pickup.h"

#include <Utility.h>

#include <SFML\Graphics\Rect.hpp>

#include <cmath>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

Aircraft::DataTable Aircraft::_dataTable = initAircraftData();

// INTERFACE
Aircraft::Aircraft(Type type, const TextureManager& textures, const FontManager& fonts) :
	Entity(_dataTable[type].hitPoints, _dataTable[type].category),
	_type(type),
	_sprite(textures[_dataTable[type].texture]),
	_traveledDistance(0),
	_directionIndex(0),
	_fireBulletCommand(
		"Fire Bullets",
		[this, &textures](SceneNode& node, Time) {
			launchBullets(node, textures);
		},
		Categories::AirSceneLayer
	),
	_launchMissileCommand(
		"Launch Missile",
		[this, &textures](SceneNode& node, Time) {
			launchProjectile(node, Projectile::Type::Missile, 0.f, 0.5f, textures);
		},
		Categories::AirSceneLayer
	),
	_fireRateLevel(1),
	_fireSpreadLevel(1)
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
void Aircraft::fire() {
	if (_dataTable[_type].fireInterval != Time::Zero)
		_isFiringBullets = true;
}
void Aircraft::launchMissile() {
	_isLaunchingMissile = true;
}
void Aircraft::collectMissiles(unsigned int numMissiles) {
	_missileAmmo += numMissiles;
}
void Aircraft::increaseSpread() {
	if (_fireSpreadLevel < MAX_FIRE_SPREAD)
		++_fireSpreadLevel;
}
void Aircraft::increaseFireRate() {
	if (_fireRateLevel < MAX_FIRE_RATE)
		++_fireRateLevel;
}

// HELPER FUNCTIONS
void Aircraft::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(this->_sprite, states);
}
void Aircraft::updateCurrent(Time dt, queue<Command>& commands) {
	launchProjectiles(dt, commands);

	updateMovementDirections(dt);
	Entity::updateCurrent(dt, commands);

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
	float speed = getMaxSpeed();
	Vector2f v(speed * sinf(radians), speed * cosf(radians));
	setVelocity(v);
	_traveledDistance += (speed * dt.asSeconds());
}
float Aircraft::getMaxSpeed() const {
	return _dataTable[_type].speed;
}
bool Aircraft::isAllied() const {
	Category c = _dataTable[_type].category;
	return c == Categories::AlliedAircraft || c == Categories::PlayerAircraft;
}
void Aircraft::launchProjectiles(Time dt, queue<Command>& commands) {
	// Enemies try to fire all the time (no input Commands needed for this)
	if (!isAllied())
		fire();

	// Reset a bullet cooldown timer each time a bullet is fired
	if (_isFiringBullets && _cooldownTime <= Time::Zero) {
		commands.push(_fireBulletCommand);
		_cooldownTime += _dataTable[_type].fireInterval / (_fireRateLevel + 1.f);
		_isFiringBullets = false;
	}
	else if (_cooldownTime > sf::Time::Zero) {
		_cooldownTime -= dt;
		_isFiringBullets = false;
	}

	// Check for missile launch
	if (_isLaunchingMissile) {
		commands.push(_launchMissileCommand);
		_isLaunchingMissile = false;
	}
}
void Aircraft::launchBullets(SceneNode& node, const TextureManager& textures) const {
	Projectile::Type type = (isAllied() ?
		Projectile::Type::AlliedBullet :
		Projectile::Type::EnemyBullet);
	switch (_fireSpreadLevel) {
	case 1:
		launchProjectile(node, type, 0.f, 0.5f, textures);
		break;
	case 2:
		launchProjectile(node, type, -0.33f, 0.33f, textures);
		launchProjectile(node, type, 0.33f, 0.33f, textures);
		break;
	case 3:
		launchProjectile(node, type, -0.5f, 0.33f, textures);
		launchProjectile(node, type, 0.f, 0.5f, textures);
		launchProjectile(node, type, 0.5f, 0.33f, textures);
		break;
	}
}
void Aircraft::launchProjectile(SceneNode& node, Projectile::Type type, float x, float y, const TextureManager& textures) const {
	// Define the new Projectile's texture/position/velocity
	Projectile::Ptr projectile(new Projectile(type, textures));
	FloatRect bounds = _sprite.getGlobalBounds();
	Vector2f offset(x * bounds.width, y * bounds.height);
	float sign = isAllied() ? -1.f : 1.f;
	projectile->setPosition(getWorldPosition() + offset * sign);
	projectile->setVelocity(sign * Vector2f(0.f, projectile->getMaxSpeed()));

	// Make it a child of the provided SceneNode
	node.attachChild(std::move(projectile));
}
