#pragma once

#include "SceneNode.h"
#include "..\GAME2D_API.h"

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>

#include <string>
#include <memory>

namespace Game2D {

	class GAME2D_API TextNode : public SceneNode {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<TextNode> Ptr;

		// ENCAPSULATED FIELDS
	private:
		sf::Text _text;

		// INTERFACE
	public:
		TextNode(const sf::Font&, const std::string&);
		void setString(const std::string&);

		// HELPER FUNCTIONS
	private:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
	};

}

