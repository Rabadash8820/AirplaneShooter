#pragma once

#include "..\GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API StateId {
		// ENCAPSULATED MEMBERS
	private:
		size_t _id;
		static size_t _root;
		static size_t incrementedRoot() {
			return (_root += 1);
		}

		// INTERFACE
	public:
		StateId() {
			_id = incrementedRoot();
		}
		StateId(const StateId& that) {
			this->_id = that._id;
		}
		bool operator==(const StateId& that) const {
			return this->_id == that._id;
		}
		bool operator!=(const StateId& that) const {
			return this->_id != that._id;
		}
		bool operator<(const StateId& that) const {
			return this->_id < that._id;
		}
		bool operator<=(const StateId& that) const {
			return this->_id <= that._id;
		}
		bool operator>(const StateId& that) const {
			return this->_id > that._id;
		}
		bool operator>=(const StateId& that) const {
			return this->_id >= that._id;
		}

	};

}
