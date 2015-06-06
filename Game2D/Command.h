#pragma once

#include "Render/SceneNode.h"
#include <SFML/System/Time.hpp>
#include <functional>

namespace Game2D {

	struct Command {
		// PROPERTIES
	public:
		std::function<void(SceneNode&, sf::Time)> Action;
		unsigned int Category;
	};

}