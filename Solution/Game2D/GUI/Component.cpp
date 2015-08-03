#include "Component.h"

using namespace Game2D::GUI;

// INTERFACE
Component::Component() :
	_isEnabled(true),
	_isSelected(false),
	_isActive(false)
{ }
Component::~Component() {}
bool Component::isEnabled() const {
	return _isEnabled;
}
void Component::enable() {
	_isEnabled = true;
}
void Component::disable() {
	_isEnabled = false;
}
bool Component::isSelected() const {
	return _isSelected;
}
void Component::select() {
	_isSelected = true;
}
void Component::unselect() {
	_isSelected = false;
}
bool Component::isActive() const {
	return _isActive;
}
void Component::activate() {
	_isActive = true;
}
void Component::deactivate() {
	_isActive = false;
}
