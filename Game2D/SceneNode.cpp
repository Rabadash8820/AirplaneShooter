#include "SceneNode.h"
#include <algorithm>
#include <cassert>

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	SceneNode::SceneNode() {}
	SceneNode::~SceneNode() {}

	// INTERFACE FUNCTIONS
	void SceneNode::attachChild(Ptr child) {
		child->_parent = this;
		_children.push_back(std::move(child));
	}
	SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
		// Try to find the child that matches the provided node
		auto child = std::find_if(_children.begin(), _children.end(),
			[&](Ptr& p)->bool { return p.get() == &node; });
		assert(child != _children.end());

		// If found, remove that child from this node and return it
		_children.erase(child);
		(*child)->_parent = nullptr;
		return std::move(*child);

	}
	void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		// Render this node with its absolute transform (parent's absolute * relative)
		states.transform *= this->getTransform();
		renderCurrent(target, states);
		renderChildren(target, states);
	}
	void SceneNode::update(sf::Time dt) {
		updateCurrent(dt);
		updateChildren(dt);
	}
	sf::Vector2f SceneNode::getWorldPosition() const {
		sf::Transform transform = sf::Transform::Identity;
		for (const SceneNode* node = this; node != nullptr; node = node->_parent)
			transform *= node->getTransform();
		return transform * sf::Vector2f();
	}

	// HELPER FUNCTIONS
	void SceneNode::updateCurrent(sf::Time dt) {
		// Do nothing by default
	}
	void SceneNode::renderCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
		// Do nothing by default
	}
	void SceneNode::renderChildren(sf::RenderTarget& target, sf::RenderStates states) const {
		for (const Ptr& child : this->_children)
			child->draw(target, states);
	}
	void SceneNode::updateChildren(sf::Time dt) {
		for (const Ptr& child : this->_children)
			child->update(dt);
	}

}