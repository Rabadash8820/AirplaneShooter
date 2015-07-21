#pragma once

#include "../GAME2D_API.h"
#include "../Render/SceneNode.h"
#include "Category.h"
#include <SFML/System/Time.hpp>
#include <initializer_list>
#include <functional>

namespace Game2D {

	class SceneNode;

	struct GAME2D_API Command {
		// INTERFACE
	public:
		Command(std::function<void(SceneNode&, sf::Time)>, Category);
		Command(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
		unsigned int category() const;
		void action(SceneNode&, sf::Time) const;

		// PRIVATE MEMBERS
	private:
		std::function<void(SceneNode&, sf::Time)> _action;
		unsigned int _categoryId;
		void initialize(std::function<void(SceneNode&, sf::Time)>, std::initializer_list<Category>);
	};

}
