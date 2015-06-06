#pragma once

#include "GAME2D_API.h"
#include "SceneNode.h"
#include <memory>

namespace Game2D {

	class GAME2D_API Brush : public SceneNode {
		// VARIABLES
	public:
		typedef std::unique_ptr<Brush> Ptr;
	private:
		sf::Sprite _sprite;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit Brush(const sf::Texture& texture);
		Brush(const sf::Texture& texture, const sf::IntRect& rect);

		// INTERFACE FUNCTIONS
	public:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	};

}