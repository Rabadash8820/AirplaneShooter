#include "Control.h"

using namespace Game2D::GUI;

// INTERFACE
Control::Control() :
	_isEnabled(true),
	_isSelected(false),
	_isActive(false)
{ }
Control::~Control() {}
bool Control::isEnabled() const {
	return _isEnabled;
}
void Control::enable() {
	_isEnabled = true;
}
void Control::disable() {
	_isEnabled = false;
}
bool Control::isSelected() const {
	return _isSelected;
}
void Control::select() {
	_isSelected = true;
}
void Control::unselect() {
	_isSelected = false;
}
bool Control::isActive() const {
	return _isActive;
}
void Control::activate() {
	_isActive = true;
}
void Control::deactivate() {
	_isActive = false;
}
