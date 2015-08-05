#include "Command.h"

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
Command::Command(string name, function<void(SceneNode&, Time)> action) :
	name(name),
	_action(action),
	category(Node)
{ }
Command::Command(string name, function<void(SceneNode&, Time)> action, Category category) :
	name(name),
	_action(action),
	category(category)
{ }
Command::Command(const Command& that) :
	name(that.name),
	_action(that._action),
	category(that.category)
{ }
void Command::action(SceneNode& node, Time dt) const {
	_action(node, dt);
}
const Command& Command::operator=(const Command& that) {
	this->name = that.name;
	this->category = that.category;
	this->_action = that._action;
	return *this;
}
