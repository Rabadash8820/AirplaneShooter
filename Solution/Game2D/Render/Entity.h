#pragma once

#include "../GAME2D_API.h"
#include "SceneNode.h"
#include "../Categories.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
		// CONSTRUCTORS
	public:
		Entity(std::unique_ptr<Categories> c) : SceneNode(std::move(c)) { }

		// PROPERTIES
	public:
		typedef std::unique_ptr<Entity> Ptr;
		sf::Vector2f Velocity;

		// METHODS
	protected:
		virtual void updateCurrent(sf::Time dt) {
			this->move(this->Velocity * dt.asSeconds());
		}

	};

}