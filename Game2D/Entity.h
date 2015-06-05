#pragma once

#include "GAME2D_API.h"
#include "SceneNode.h"
#include <SFML/Graphics.hpp>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
		// PROPERTIES
	public:
		sf::Vector2f Velocity;

		// METHODS
	protected:
		virtual void updateCurrent(sf::Time dt) {
			this->move(this->Velocity * dt.asSeconds());
		}

	};

}