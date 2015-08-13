#pragma once

#include "Entity.h"
#include "..\Ids\TextureId.h"
#include "..\Categories.h"

#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Time.hpp>

#include <queue>
#include <memory>

namespace Shooter {

	struct ProjectileData;

	class Projectile : public Entity {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Projectile> Ptr;
		enum class Type {
			AlliedBullet,
			EnemyBullet,
			Missile,
		};
		typedef std::map<Type, ProjectileData> DataTable;

		// ENCAPSULATED FIELDS
	private:
		Type _type;
		sf::Sprite _sprite;
		sf::Vector2f _targetDirection;
		static DataTable _dataTable;
		
		// INTERFACE
	public:
		Projectile(Type, const TextureManager&);
		void guideTowards(sf::Vector2f);
		bool isGuided() const;
		virtual Game2D::Category getCategory() const;
		virtual sf::FloatRect getBoundingRect() const;
		float getMaxSpeed() const;
		int getDamage() const;

		// HELPER FUNCTIONS
	private:
		virtual void updateCurrent(sf::Time, std::queue<Game2D::Command>&);
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;

	};

}
