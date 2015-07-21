#include "Category.h"

using namespace Game2D;

// PRIVATE STATIC MEMBERS
unsigned int Category::_root = 1;
unsigned int Category::shiftedRoot() {
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
