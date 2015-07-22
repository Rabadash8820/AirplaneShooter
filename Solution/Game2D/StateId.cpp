#include "StateId.h"

using namespace Game2D;

// PRIVATE STATIC MEMBERS
unsigned int StateId::_root = 0;
unsigned int StateId::incrementedRoot() {
	return (_root += 1);
}

// INTERFACE
StateId::StateId() {
	_id = incrementedRoot();
}
unsigned int StateId::getId() const {
	return _id;
}
bool StateId::operator<(const StateId& that) const {
	return this->_id < that._id;
}
StateId::operator unsigned int() const {
	return this->_id;
}
