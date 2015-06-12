#pragma once

#include "../GAME2D_API.h"
#include "../Render/SceneNode.h"
#include <SFML/System/Time.hpp>
#include <functional>

namespace Game2D {

	class SceneNode;

	struct GAME2D_API Command {
		// CONSTRUCTORS
	public:
		Command();

		// PROPERTIES
	public:
		std::function<void(SceneNode&, sf::Time)> Action;
		unsigned int Category;
	};

}