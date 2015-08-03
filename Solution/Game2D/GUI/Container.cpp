#include "Container.h"

#include <SFML\Graphics\RenderTarget.hpp>

using namespace Game2D::GUI;
using namespace sf;

Container::Container() :
	_selectedChild(-1)
{ }
void Container::pack(Component::Ptr component) {
	_children.push_back(component);

	if (!hasSelection() && component->isSelectable())
		select(_children.size() - 1);
}
bool Container::isSelectable() const {
	return false;
}
void Container::handleEvent(const sf::Event& e) {
	// If we have selected a child then forward the Event to it
	if (hasSelection() && _children[_selectedChild]->isActive())
		_children[_selectedChild]->handleEvent(e);

	// Otherwise, handle specific types of Events
	switch (e.type) {
	case Event::KeyReleased:
		handleKeyRelease(e.key);
		break;

	case Event::MouseButtonPressed:
		handleMousePress(e.mouseButton);
		break;

	case Event::MouseButtonReleased:
		handleMouseRelease(e.mouseButton);
		break;

	case Event::MouseMoved:
		handleMouseMove(e.mouseMove);
		break;

	case Event::MouseWheelScrolled:
		handleMouseScroll(e.mouseWheelScroll);
		break;

	default:
		return;
	}
}

// HELPER FUNCTIONS
void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	for (const Component::Ptr& child : _children)
		target.draw(*child, states);
}
bool Container::hasSelection() const {
	return _selectedChild >= 0;
}
void Container::select(std::size_t index) {
	// Don't select unselectable components...
	if (!_children[index]->isSelectable())
		return;

	// Unselect the previous selection and select the new one
	if (hasSelection())
		_children[_selectedChild]->unselect();
	_children[index]->select();
	_selectedChild = index;
}
void Container::selectNext() {
	if (!hasSelection())
		return;

	// Select the next component that is selectable, wrapping around if necessary
	int next = _selectedChild;
	do
		next = (next + 1) % _children.size();
	while (!_children[next]->isSelectable());
	select(next);

}
void Container::selectPrevious() {
	if (!hasSelection())
		return;

	// Select the previous component that is selectable, wrapping around if necessary
	int prev = _selectedChild;
	do
		prev = (prev + _children.size() - 1) % _children.size();
	while (!_children[prev]->isSelectable());
	select(prev);
}
void Container::handleKeyRelease(const sf::Event::KeyEvent& key) {
	switch (key.code) {
		// Cycle through contained Components
	case Keyboard::W:
	case Keyboard::Up:
		selectPrevious();
		break;
	case Keyboard::S:
	case Keyboard::Down:
		selectNext();
		break;

		// Activate the selected Component
	case Keyboard::Return:
	case Keyboard::Space:
		if (hasSelection())
			_children[_selectedChild]->activate();
		break;
	}
}
void Container::handleMousePress(const sf::Event::MouseButtonEvent& e) {

}
void Container::handleMouseRelease(const sf::Event::MouseButtonEvent& e) {

}
void Container::handleMouseMove(const sf::Event::MouseMoveEvent& e) {

}
void Container::handleMouseScroll(const sf::Event::MouseWheelScrollEvent& e) {

}
