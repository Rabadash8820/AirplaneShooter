#pragma once

#include <SceneNode.h>

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>

#include <memory>

namespace Shooter {

	class Brush : public Game2D::SceneNode {
		// VARIABLES
	public:
		typedef std::unique_ptr<Brush> Ptr;
	private:
		sf::Sprite _sprite;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Brush(const sf::Texture& texture);
		Brush(const sf::Texture& texture, const sf::IntRect& rect);

		// INTERFACE FUNCTIONS
	public:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	};

}
