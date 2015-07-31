#include "ResourceId.h"

using namespace Game2D;

// PRIVATE STATIC MEMBERS
unsigned int ResourceId::_root = 0;
unsigned int ResourceId::incrementedRoot() {
	return (_root += 1);
}

// INTERFACE
ResourceId::ResourceId() {
	_id = incrementedRoot();
}
unsigned int ResourceId::getId() const {
	return _id;
}
bool ResourceId::operator<(const ResourceId& that) const {
	return this->_id < that._id;
}
