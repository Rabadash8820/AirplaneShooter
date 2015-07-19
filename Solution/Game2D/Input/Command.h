#pragma once

#include "../Render/SceneNode.h"
#include "Category.h"
#include <SFML/System/Time.hpp>
#include <initializer_list>
#include <functional>

namespace Game2D {

	class Command {
	private:
		unsigned int _categoryId;

		// INTERFACE
	public:
		explicit Command(Category);
		Command(std::initializer_list<Category>);
		Command(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
		std::function<void(SceneNode&, sf::Time)> Action;
		void setCategory(std::initializer_list<Category>);
		unsigned int getCategory() const;

		// HELPER FUNCTIONS
	private:
		void initialize(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
	};

}