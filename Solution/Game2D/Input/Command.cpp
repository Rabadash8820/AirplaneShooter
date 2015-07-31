#include "Command.h"
#include "Category.h"

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
Command::Command(function<void(SceneNode&, Time)> action) {
	this->initialize(action, { Node });
}
Command::Command(function<void(SceneNode&, Time)> action, Category category) {
	this->initialize(action, { category });
}
Command::Command(function<void(SceneNode&, Time)> action, initializer_list<Category> categories) {
	this->initialize(action, categories);
}
void Command::action(SceneNode& node, Time dt) const {
	_action(node, dt);
}
unsigned int Command::getCategory() const {
	return _categoryId;
}
void Command::setCategory(Category category) {
	this->initialize(_action, { category });

}
void Command::setCategory(std::initializer_list<Category> categories) {
	this->initialize(_action, categories);
}

// HELPER FUNCTIONS
void Command::initialize(function<void(SceneNode&, Time)> action, initializer_list<Category> categories) {
	// Set action
	_action = action;

	// Set category (bitwise OR of all those provided)
	unsigned int id = 0;
	for (auto& c : categories)
		id |= c.getId();
	_categoryId = id;
}
