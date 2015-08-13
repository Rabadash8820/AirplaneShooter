#include "Projectile.h"

#include "..\DataTables.h"
#include "..\Categories.h"

#include <Utility.h>

using namespace Shooter;
using namespace Game2D;

Projectile::DataTable Projectile::_dataTable = initProjectileData();

// INTERFACE
Projectile::Projectile(Type type, const TextureManager& textures) :
	Entity(1),
	_type(type),
	_sprite(textures[_dataTable[_type].texture])
{
	Utility::centerOrigin(_sprite);
}
void Projectile::guideTowards(sf::Vector2f) {

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
void Projectile::updateCurrent(sf::Time, std::queue<Game2D::Command>&) {

}
void Projectile::drawCurrent(sf::RenderTarget&, sf::RenderStates) const {

}
