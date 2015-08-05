#pragma once

#include "../GAME2D_API.h"

#include <initializer_list>

namespace Game2D {

	struct GAME2D_API Category {
		// ENCAPSULATED MEMBERS
	private:
		unsigned long _id;
		static unsigned long _root;
		static unsigned long shiftedRoot();

		// INTERFACE
	public:
		Category();
		Category(const Category& that);

		bool matches(const Category& that) const;

		bool operator==(const Category& that) const;
		bool operator!=(const Category& that) const;
		const Category& operator|(const Category& that) const;
		const Category& operator&(const Category& that) const;
		const Category& operator=(const Category& that);
		const Category& operator|=(const Category& that);
		const Category& operator&=(const Category& that);

	};

	// Define the most general Category for use by any Game
	extern GAME2D_API Category Node;

}
