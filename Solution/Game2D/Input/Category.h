#pragma once

#include "../GAME2D_API.h"

#include <initializer_list>

namespace Game2D {

	struct GAME2D_API Category {
		// ENCAPSULATED MEMBERS
	private:
		size_t _id;
		static size_t _root;
		static size_t shiftedRoot();

		// INTERFACE
	public:
		Category();
		Category(const Category& that);

		bool matches(const Category& that) const;

		bool operator==(const Category& that) const;
		bool operator!=(const Category& that) const;
		friend Category operator|(Category left, const Category& right);
		friend Category operator&(Category left, const Category& right);
		const Category& operator=(const Category& that);
		const Category& operator|=(const Category& that);
		const Category& operator&=(const Category& that);

	};

	// Define the most general Category for use by any Game
	extern GAME2D_API Category Node;

}
