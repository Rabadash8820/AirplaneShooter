#include "Label.h"

#include <SFML\Graphics\RenderTarget.hpp>

using namespace Game2D::GUI;

Label::Label(const std::string& text, const sf::Font& font) :
	_text(text, font, 16)
{ }
bool Label::isSelectable() const {
	return false;
}
void Label::setText(const std::string& text) {
	_text.setString(text);
}
void Label::setCharacterSize(unsigned int size) {
	_text.setCharacterSize(size);
}
void Label::handleEvent(const sf::Event& e) { }

// HELPER FUNCTIONS
void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(_text, states);
}
