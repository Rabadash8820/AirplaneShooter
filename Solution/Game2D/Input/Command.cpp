#include "Command.h"
#include "Category.h"

using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
Command::Command(Category category) {
	this->initialize(
		[](SceneNode& sn, Time dt) {},
		{ category });
}
Command::Command(initializer_list<Category> categories) {
	this->initialize(
		[](SceneNode& sn, Time dt) {},
		categories);
}
Command::Command(function<void(SceneNode&, Time)> action, initializer_list<Category> categories) {
	this->initialize(action, categories);
}
void Command::setCategory(initializer_list<Category> categories) {
	this->initialize(this->Action, categories);
}
unsigned int Command::getCategory() const {
	return _categoryId;
}

// HELPER FUNCTIONS
void Command::initialize(function<void(SceneNode&, Time)> action, initializer_list<Category> categories) {
	// Set action
	this->Action = action;

	// Set category (bitwise OR of all those provided)
	unsigned int id;
	for (auto& c : categories)
		id |= c.getId();
	_categoryId = id;
}