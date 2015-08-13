#include "SceneNode.h"

#include "Input/Category.h"

#include <algorithm>
#include <cassert>

using namespace Game2D;
using namespace sf;
using namespace std;

// CONSTRUCTORS / DESTRUCTOR
SceneNode::SceneNode() { }

// INTERFACE FUNCTIONS
void SceneNode::attachChild(Ptr child) {
	child->_parent = this;
	_children.push_back(std::move(child));
}
SceneNode::~SceneNode() {}

// INTERFACE FUNCTIONS
void SceneNode::attachChild(Ptr child) {
	child->_parent = this;
	_children.push_back(std::move(child));
}
SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
	// Try to find the child that matches the provided node
	auto child = find_if(
		_children.begin(),
		_children.end(),
		[&](Ptr& p)->bool { return p.get() == &node; });
	assert(child != _children.end());

	// If found, remove that child from this node and return it
	_children.erase(child);
	(*child)->_parent = nullptr;
	return std::move(*child);
}
SceneNode::Ptr SceneNode::detachChild(SceneNode* node) {
	// Try to find the child that matches the provided node
	auto child = find_if(
		_children.begin(),
		_children.end(),
		[&](Ptr& p)->bool { return p.get() == node; });
	assert(child != _children.end());

	// If found, remove that child from this node and return it
	_children.erase(child);
	(*child)->_parent = nullptr;
	return std::move(*child);
}
void SceneNode::draw(RenderTarget& target, RenderStates states) const {
	// Render this node with its absolute transform (parent's absolute * relative)
	states.transform *= this->getTransform();
	drawCurrent(target, states);
	drawChildren(target, states);
}
void SceneNode::update(Time dt) {
	updateCurrent(dt);
	updateChildren(dt);
}
Vector2f SceneNode::getWorldPosition() const {
	Transform transform = Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->_parent)
		transform *= node->getTransform();
	return transform * Vector2f();
}
unsigned int SceneNode::getCategory() const {
	return _categories->Node();
}
void SceneNode::giveCommand(const Command& command, sf::Time dt) {
	// If this node is in one of the Command's affected categories, then perform the Command's action
	if (command.Category & this->getCategory())
		command.Action(*this, dt);

	// Pass the command to all children
	for (Ptr& child : this->_children)
		child->giveCommand(command, dt);
}

// HELPER FUNCTIONS
void SceneNode::updateCurrent(Time dt) { }
void SceneNode::drawCurrent(RenderTarget& target, RenderStates states) const { }
void SceneNode::drawChildren(RenderTarget& target, RenderStates states) const {
	for (const Ptr& child : this->_children)
		target.draw(*child, states);
}
void SceneNode::updateChildren(Time dt) {
	for (const Ptr& child : this->_children)
		child->update(dt);
}