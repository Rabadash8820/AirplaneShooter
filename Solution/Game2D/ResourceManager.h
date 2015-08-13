#pragma once

#include <map>
#include <memory>
#include <string>

namespace Game2D {

	template<typename Resource, typename Id>
	class ResourceManager {
	private:
		// VARIABLES
		typedef std::unique_ptr<Resource> Ptr;
		std::map<Id, Ptr> _resources;
		
	public:
		// CONSTRUCTORS / DESTRUCTOR
		ResourceManager();

		// FUNCTIONS
		void load(Id, const std::string&);
		template<typename Param>
		void load(Id, const std::string&, Param);
		Resource& get(Id) const;
		Resource& operator[](Id) const;
	};

#include "ResourceManager.inl"

}
