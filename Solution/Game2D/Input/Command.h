#pragma once

#include "../GAME2D_API.h"

#include "Category.h"

#include <SFML/System/Time.hpp>

#include <initializer_list>
#include <functional>
#include <string>

namespace Game2D {

	class SceneNode;

	struct GAME2D_API Command {
		// ENCAPSULATED FIELDS
	private:
		std::function<void(SceneNode&, sf::Time)> _action;

		// INTERFACE
	public:
		Command(std::string, std::function<void(SceneNode&, sf::Time)>);
		Command(std::string, std::function<void(SceneNode&, sf::Time)>, Category);
		Command(const Command&);
		std::string name;
		Category category;
		void action(SceneNode&, sf::Time) const;
		const Command& operator=(const Command&);
	};

}
