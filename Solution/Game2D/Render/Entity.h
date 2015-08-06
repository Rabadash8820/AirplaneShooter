#pragma once

#include "../GAME2D_API.h"
#include "SceneNode.h"

#include <SFML\System\Vector2.hpp>

#include <memory>

namespace Game2D {

	class GAME2D_API Entity : public SceneNode {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Entity> Ptr;

		// ENCAPSULATED FIELDS
	protected:
		int _hitPoints;

		// INTERFACE
	public:
		explicit Entity(int);
		sf::Vector2f velocity;
		void heal(int);
		void damage(int);
		void destory();
		int getHitPoints() const;
		bool isDestroyed() const;

		// HELPER FUNCTIONS
	protected:
		virtual void updateCurrent(sf::Time dt) {
			this->move(this->velocity * dt.asSeconds());
		}

	};

}
