#pragma once

#include <map>
#include <memory>
#include <string>
#include <cassert>

namespace Game2D {

	template<typename Id, typename Resource>
	class ResourceHolder {
	private:
		// VARIABLES
		std::map<Id, std::unique_ptr<Resource> > _resources;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		ResourceHolder();
		~ResourceHolder();

		// FUNCTIONS
		void load(Id, const std::string&);
		template<typename Param>
		void load(Id, const std::string&, Param);
		Resource& operator[](Id) const;
	};

#include "ResourceHolder.inl"

}