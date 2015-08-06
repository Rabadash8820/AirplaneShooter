#include "TextNode.h"

#include "..\Utility.h"

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
TextNode::TextNode(const Font& font, const string& text) :
	_text(text, font, 20)
{ }
void TextNode::setString(const string& text) {
	// Adjust the size of the Text object to fit the new string
	_text.setString(text);
	Utility::centerOrigin(_text);
}

// HELPER FUNCTIONS
void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_text, states);
}
