#include "Button.h"

#include "..\Utility.h"

#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RenderTarget.hpp>

using namespace Game2D;
using namespace Game2D::GUI;
using namespace sf;
using namespace std;

Button::Button(const sf::Font& font, const TextureManager& textures) :
	_text("", font, 16),
	_isToggle(false)
{
	// Store the Textures for each Button state
	_textures[State::Unselected] = &textures[State::Unselected];
	_textures[State::Selected]	 = &textures[State::Selected];
	_textures[State::Pressed]	 = &textures[State::Pressed];
	_textures[State::Disabled]	 = &textures[State::Disabled];

	// Initialize the Button
	_sprite.setTexture(*_textures[State::Unselected]);
	FloatRect bounds = _sprite.getLocalBounds();
	_text.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}
void Button::setCallback(Callback callback) {
	_callback = callback;
}
void Button::setText(const std::string& text) {
	_text.setString(text);
	Utility::centerOrigin(_text);
}
void Button::setToggle(bool flag) {
	_isToggle = flag;
}
bool Button::isSelectable() const {
	return isEnabled();
}
void Button::select() {
	Control::select();
	_sprite.setTexture(*_textures[State::Selected]);
}
void Button::unselect() {
	Control::select();
	State s = isEnabled() ? State::Unselected : State::Disabled;
	_sprite.setTexture(*_textures[s]);
}
void Button::activate() {
	Control::activate();

	if (_isToggle)
		_sprite.setTexture(*_textures[State::Pressed]);
	if (_callback)
		_callback();
	if (!_isToggle)
		deactivate();
}
void Button::deactivate() {
	Control::deactivate();

	if (_isToggle) {
		if (isSelected())
			_sprite.setTexture(*_textures[State::Selected]);
		else
			_sprite.setTexture(*_textures[State::Unselected]);
	}
}
void Button::enable() {
	Control::enable();
	_sprite.setTexture(*_textures[State::Unselected]);
}
void Button::disable() {
	Control::disable();
	_sprite.setTexture(*_textures[State::Disabled]);
}
void Button::handleEvent(const sf::Event& event) {

}

// HELPER FUNCTIONS
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(_sprite, states);
	target.draw(_text, states);
}
