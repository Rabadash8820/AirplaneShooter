#pragma once

#include "../GAME2D_API.h"
namespace Game2D {

	struct GAME2D_API Category {
		// PRIVATE MEMBERS
	private:
		unsigned int _id;

		// PRIVATE STATIC MEMBERS
	private:
		static unsigned int _root;
		static unsigned int shiftedRoot() {
			return (_root <<= 1);
		}

		// INTERFACE
	public:
		Category() {
			_id = shiftedRoot();
		}
		unsigned int getId() const {
			return _id;
		}
		unsigned int operator|(const Category& that) const {
			return this->_id | that._id;
		}
		operator unsigned int() const {
			return this->_id;
		}
	};

	unsigned int Category::_root = 1;

}
