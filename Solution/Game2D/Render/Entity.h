#pragma once

#include "../GAME2D_API.h"
#include "SceneNode.h"

#include <SFML\System\Vector2.hpp>

#include <memory>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
		// PROPERTIES
	public:
		typedef std::unique_ptr<Entity> Ptr;
		sf::Vector2f velocity;

		// METHODS
	protected:
		virtual void updateCurrent(sf::Time dt) {
			this->move(this->velocity * dt.asSeconds());
		}

	};

}
