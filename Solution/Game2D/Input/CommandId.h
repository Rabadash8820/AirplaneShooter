#pragma once

#include "..\GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API CommandId {
		// ENCAPSULATED MEMBERS
	private:
		size_t _id;
		static size_t _root;
		static size_t incrementedRoot() {
			return (_root += 1);
		}

		// INTERFACE
	public:
		CommandId() : _id(incrementedRoot()) {}
		CommandId(const CommandId& that) : _id(that._id) {}
		CommandId& operator=(const CommandId& that) {
			this->_id = that._id;
			return *this;
		}
		bool operator==(const CommandId& that) const {
			return this->_id == that._id;
		}
		bool operator!=(const CommandId& that) const {
			return this->_id != that._id;
		}
		bool operator<(const CommandId& that) const {
			return this->_id < that._id;
		}
		bool operator<=(const CommandId& that) const {
			return this->_id <= that._id;
		}
		bool operator>(const CommandId& that) const {
			return this->_id > that._id;
		}
		bool operator>=(const CommandId& that) const {
			return this->_id >= that._id;
		}

	};

}
