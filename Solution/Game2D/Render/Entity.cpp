#include "Entity.h"

using namespace Game2D;

// INTERFACE
Entity::Entity(int hp) :
	_hitPoints(hp),
	velocity(0.f, 0.f)
{ }
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
