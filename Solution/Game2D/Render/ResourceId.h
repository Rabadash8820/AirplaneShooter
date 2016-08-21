#pragma once

#include "../GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API ResourceId {
		// ENCAPSULATED MEMBERS
	private:
		size_t _id;
		static size_t _root;
		static size_t incrementedRoot() {
			return (_root += 1);
		}

		// INTERFACE
	public:
		ResourceId() {
			_id = incrementedRoot();
		}
		ResourceId(const ResourceId& that) {
			this->_id = that._id;
		}
		bool operator==(const ResourceId& that) const {
			return this->_id == that._id;
		}
		bool operator!=(const ResourceId& that) const {
			return this->_id != that._id;
		}
		bool operator<(const ResourceId& that) const {
			return this->_id < that._id;
		}
		bool operator<=(const ResourceId& that) const {
			return this->_id <= that._id;
		}
		bool operator>(const ResourceId& that) const {
			return this->_id > that._id;
		}
		bool operator>=(const ResourceId& that) const {
			return this->_id >= that._id;
		}

	};

}
