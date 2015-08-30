#include "Projectile.h"

#include "..\DataTables.h"
#include "..\Categories.h"

#include <Utility.h>

using namespace Shooter;
using namespace Game2D;
using namespace std;
using namespace sf;

Projectile::DataTable Projectile::_dataTable = initProjectileData();

// INTERFACE
Projectile::Projectile(Type type, const TextureManager& textures) :
	Entity(1),
	_type(type),
	_sprite(textures[_dataTable[type].texture])
{
	Utility::centerOrigin(_sprite);
}
void Projectile::guideTowards(Vector2f target) {
	assert(isGuided());
	_targetDirection = Utility::unitVector(target - getWorldPosition());
}
bool Projectile::isGuided() const {
	return _type == Type::Missile;
}
Game2D::Category Projectile::getCategory() const {
	// All Aircraft are SceneNodes
	Category c = SceneNode::getCategory();

	// Adjust the game Category of this Aircraft depending on its type
	switch (_type) {
	case Type::EnemyBullet:
		return Category({ c, Categories::EnemyProjectile });
	default:
		return Category({ c, Categories::AlliedProjectile });
	}
	return c;
}
sf::FloatRect Projectile::getBoundingRect() const {
	return getWorldTransform().transformRect(_sprite.getGlobalBounds());
}
float Projectile::getMaxSpeed() const {
	return _dataTable[_type].speed;
}
int Projectile::getDamage() const {
	return _dataTable[_type].damage;
}

// HELPER FUNCTIONS
void Projectile::updateCurrent(Time dt, queue<Command>& commands) {
	// If this is a guided projectile...
	if (isGuided()) {
		// Get weighted sum of current- and target-velocity vectors
		Vector2f vCurrent = getVelocity();
		Vector2f vToTarget = dt.asSeconds() * _targetDirection;
		Vector2f v = Utility::unitVector(vCurrent + TARGET_WEIGHT * vToTarget);
		
		// Set Projectile's resultant vector and rotation accordingly
		float angle = atan2(v.y, v.x);
		setRotation(Utility::toDegrees(angle) + 90.f);
		setVelocity(getMaxSpeed() * v);
	}

	// Let the base Entity handle moving with this velocity
	Entity::updateCurrent(dt, commands);
}
void Projectile::drawCurrent(RenderTarget& target, RenderStates states) const {
	target.draw(_sprite, states);
}
