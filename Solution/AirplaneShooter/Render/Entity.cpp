#include "Entity.h"

using namespace Shooter;
using namespace sf;

// INTERFACE
Entity::Entity(int hp) :
	_hitPoints(hp)
{ }
Entity::~Entity() { }
void Entity::heal(int hp) {
	_hitPoints += hp;
}
void Entity::damage(int hp) {
	_hitPoints -= hp;
}
void Entity::destory() {
	_hitPoints = 0;
}
int Entity::getHitPoints() const {
	return _hitPoints;
}
bool Entity::isDestroyed() const {
	return _hitPoints <= 0;
}
void Entity::setVelocity(Vector2f velocity) {
	_velocity = velocity;
}
sf::Vector2f Entity::getVelocity() const {
	return _velocity;
}

// HELPER FUNCTIONS
void Entity::updateCurrent(Time dt) {
	move(_velocity * dt.asSeconds());
}
