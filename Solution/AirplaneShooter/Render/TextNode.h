#pragma once

#include <SceneNode.h>

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>

#include <string>
#include <memory>

namespace Shooter {

	class TextNode : public Game2D::SceneNode {
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

