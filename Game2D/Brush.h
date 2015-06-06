#pragma once

#include "GAME2D_API.h"
#include "SceneNode.h"

namespace Game2D {

	class Brush : public SceneNode {
	private:
		sf::Sprite _sprite;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit Brush(const sf::Texture& texture) :
			_sprite(texture)
		{
			
		}
		Brush(const sf::Texture& texture, const sf::IntRect& rect) :
			_sprite(texture, rect)
		{

		}

		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const { }

	};

}