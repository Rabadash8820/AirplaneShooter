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
		static unsigned int shiftedRoot();

		// INTERFACE
	public:
		Category();
		unsigned int getId() const;
		unsigned int operator|(const Category& that) const;
		operator unsigned int() const;
	};

	// Define the most general Category for use by any Game
	extern GAME2D_API Category Node;

}
