#pragma once

#include "GAME2D_API.h"
#include "SceneNode.h"
#include <SFML/Graphics.hpp>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
	public:
		sf::Vector2f Velocity;

	private:
		virtual void updateCurrent(sf::Time dt) {
			sf::Transformable::move(Velocity * dt.asSeconds());
		}

	};

}