#pragma once

#include "..\GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API StateId {
		// ENCAPSULATED FIELDS
	private:
		unsigned int _id;

		// STATIC MEMBERS
	private:
		static unsigned int _root;
		static unsigned int incrementedRoot();

		// INTERFACE
	public:
		StateId();
		unsigned int getId() const;
		bool operator<(const StateId& that) const;
	};

}
