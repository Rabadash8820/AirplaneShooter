#pragma once

#include "../GAME2D_API.h"

#include "Category.h"

#include <SFML/System/Time.hpp>

#include <initializer_list>
#include <functional>

namespace Game2D {

	class SceneNode;

	struct GAME2D_API Command {
		// ENCAPSULATED FIELDS
	private:
		std::function<void(SceneNode&, sf::Time)> _action;
		unsigned int _categoryId;

		// INTERFACE
	public:
		Command(std::function<void(SceneNode&, sf::Time)>);
		Command(std::function<void(SceneNode&, sf::Time)>, Category);
		Command(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
		unsigned int getCategory() const;
		void action(SceneNode&, sf::Time) const;
		void setCategory(Category);
		void setCategory(std::initializer_list<Category>);

		// HELPER FUNCTIONS
		void initialize(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
	};

}
