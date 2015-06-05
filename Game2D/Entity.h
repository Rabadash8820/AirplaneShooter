#pragma once

#include "GAME2D_API.h"
#include "SceneNode.h"
#include <SFML/Graphics.hpp>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
	public:
		// PROPERTIES
		sf::Vector2f Velocity;

	private:
		// METHODS
		virtual void updateCurrent(sf::Time dt) {
			move(this->Velocity * dt.asSeconds());
		}

	};

}