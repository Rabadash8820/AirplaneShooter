#include "Category.h"

using namespace Game2D;

// STATIC MEMBERS
unsigned int Category::_root = 0;
unsigned int Category::shiftedRoot() {
	if (_root == 0)
		return (_root = 1);
	return (_root <<= 1);
}

// INTERFACE
Category::Category() {
	_id = shiftedRoot();
}
unsigned int Category::getId() const {
	return _id;
}
unsigned int Category::operator|(const Category& that) const {
	return this->_id | that._id;
}
Category::operator unsigned int() const {
	return this->_id;
}

namespace Game2D {
	Category Node;
}
