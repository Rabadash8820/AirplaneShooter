#pragma once

#include "../GAME2D_API.h"

namespace Game2D {

	struct GAME2D_API ResourceId {
		// PRIVATE MEMBERS
	private:
		unsigned int _id;

		// PRIVATE STATIC MEMBERS
	private:
		static unsigned int _root;
		static unsigned int incrementedRoot();

		// INTERFACE
	public:
		ResourceId();
		unsigned int getId() const;
		bool operator<(const ResourceId& that) const;
	};

}
