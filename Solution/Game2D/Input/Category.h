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
		Category(const Category&);
		Category(std::initializer_list<Category>);

		bool matches(const Category&) const;

		bool operator==(const Category&) const;
		bool operator!=(const Category&) const;
		const Category& operator=(const Category&);

	};

	// Define the most general Category for use by any Game
	extern GAME2D_API Category Node;

}
