#pragma once

#include <Render\ResourceId.h>
#include <Render\ResourceManager.h>
#include <Render\Entity.h>
#include <Render\TextNode.h>
#include <Input\Category.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Time.hpp>

#include <memory>
#include <map>

namespace Shooter {
	struct AircraftData;
}

namespace Shooter {
	
	class Aircraft : public Game2D::Entity {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Aircraft> Ptr;
		enum class Type {
			EAGLE,
			RAPTOR,
		};
		typedef std::map<Aircraft::Type, AircraftData> DataTable;

		// ENCAPSULATED FIELDS
	private:
		Type _type;
		sf::Sprite _sprite;
		Game2D::TextNode* _hpDisplay;
		static DataTable _dataTable;

		// INTERFACE
	public:
		float airSpeed;
		Aircraft(Type, const Game2D::TextureManager&, const Game2D::FontManager&);
		virtual Game2D::Category getCategory() const; 

		// HELPER FUNCTIONS
	private:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time);
		Game2D::ResourceId textureIdForType(Type);

	};

}
