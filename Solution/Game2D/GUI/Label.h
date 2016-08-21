#pragma once

#include "Control.h"
#include "..\GAME2D_API.h"

#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>

#include <string>
#include <memory>

namespace Game2D {
	namespace GUI {

		class GAME2D_API Label : public Control {
			// ABSTRACT DATA TYPES
		public:
			typedef std::shared_ptr<Label> Ptr;

			// ENCAPSULATED FIELDS
		private:
			sf::Text _text;

			// INTERFACE
		public:
			Label(const std::string&, const sf::Font&);
			virtual bool isSelectable() const;
			void setText(const std::string&);
			void setCharacterSize(unsigned int);
			virtual void handleEvent(const sf::Event&);

			// HELPER FUNCTIONS
		private:
			void draw(sf::RenderTarget&, sf::RenderStates) const;
		};

	}
}
