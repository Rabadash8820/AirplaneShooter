#pragma once

#include "GAME2D_API.h"
namespace Game2D {

	class GAME2D_API Category {
	private:
		unsigned int _id;
		static unsigned int _root;

	public:
		Category() {
			_id = _root << 1;
		}
		unsigned int id() {
			return _id;
		}
	};

	unsigned int Category::_root = 1;

}
