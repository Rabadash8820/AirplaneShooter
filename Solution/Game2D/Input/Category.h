#pragma once

#include "../GAME2D_API.h"
namespace Game2D {

	struct GAME2D_API Category {
	private:
		unsigned int _id;
		static unsigned int _root;

	public:
		Category() {
			_id = _root << 1;
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

	//unsigned int Category::_root = 1;

}
