#include "Category.h"

using namespace Game2D;

// INTERFACE
Category::Category() :
	_id(shiftedRoot()) { }
Category::Category(const Category& that) :
	_id(that._id) { }

bool Category::matches(const Category& that) const {
	return this->_id & that._id;
}

bool Category::operator==(const Category& that) const {
	return this->_id == that._id;
}
bool Category::operator!=(const Category& that) const {
	return this->_id != that._id;
}
const Category& Category::operator=(const Category& that) {
	this->_id = that._id;
	return *this;
}
const Category& Category::operator|=(const Category& that) {
	this->_id |= that._id;
	return *this;
}
const Category& Category::operator&=(const Category& that) {
	this->_id &= that._id;
	return *this;
}

// STATIC INITIALIZATIONS
size_t Category::_root = 0;
size_t Category::shiftedRoot() {
	if (_root == 0)
		return (_root = 1);
	return (_root <<= 1);
}

namespace Game2D {
	Category operator|(Category left, const Category& right) {
		return left |= right;
	}
	Category operator&(Category left, const Category& right) {
		return left &= right;
	}

	Category Node;
}
