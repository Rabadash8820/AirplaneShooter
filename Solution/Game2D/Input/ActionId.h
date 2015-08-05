#pragma once

#include "..\GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API ActionId {
		// ENCAPSULATED MEMBERS
	private:
		size_t _id;
		static size_t _root;
		static size_t incrementedRoot() {
			return (_root += 1);
		}

		// INTERFACE
	public:
		ActionId() : _id(incrementedRoot()) { }
		ActionId(const ActionId& that) : _id(that._id) {}
		ActionId& operator=(const ActionId& that) {
			this->_id = that._id;
			return *this;
		}
		bool operator==(const ActionId& that) const {
			return this->_id == that._id;
		}
		bool operator!=(const ActionId& that) const {
			return this->_id != that._id;
		}
		bool operator<(const ActionId& that) const {
			return this->_id < that._id;
		}
		bool operator<=(const ActionId& that) const {
			return this->_id <= that._id;
		}
		bool operator>(const ActionId& that) const {
			return this->_id > that._id;
		}
		bool operator>=(const ActionId& that) const {
			return this->_id >= that._id;
		}

	};

}
