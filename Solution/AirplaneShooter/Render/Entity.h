#pragma once

#include <SceneNode.h>
#include <Input\Category.h>

#include <SFML\System\Vector2.hpp>

#include <memory>
#include <queue>

namespace Shooter {

	class Entity : public Game2D::SceneNode {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Entity> Ptr;

		// ENCAPSULATED FIELDS
	protected:
		sf::Vector2f _velocity;
		int _hitPoints;

		// INTERFACE
	public:
		explicit Entity(int);
		Entity(int, Game2D::Category);
		virtual ~Entity();
		void heal(int);
		void damage(int);
		void destory();
		int getHitPoints() const;
		bool isDestroyed() const;
		void setVelocity(sf::Vector2f);
		sf::Vector2f getVelocity() const;

		// HELPER FUNCTIONS
	protected:
		virtual void updateCurrent(sf::Time, std::queue<Game2D::Command>&);

	};

}
