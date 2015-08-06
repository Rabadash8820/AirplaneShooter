#pragma once

#include "Control.h"
#include "..\GAME2D_API.h"

#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>

#include <memory>
#include <vector>

namespace Game2D {
	namespace GUI {

		class GAME2D_API Container : public Control {
			// ABSTRACT DATA TYPES
		public:
			typedef std::shared_ptr<Container> Ptr;

			// ENCAPSULATED FIELDS
		private:
			std::vector<Control::Ptr> _children;
			int _selectedChild;

			// INTERFACE
		public:
			Container();
			void pack(Control::Ptr component);
			virtual bool isSelectable() const;
			virtual void handleEvent(const sf::Event&);
			static const sf::Keyboard::Key activationKey = sf::Keyboard::Return;

			// HELPER FUNCTIONS
		private:
			virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
			bool hasSelection() const;
			void select(std::size_t);
			void selectNext();
			void selectPrevious();
			void handleKeyRelease(	const sf::Event::KeyEvent&);
			void handleMousePress(	const sf::Event::MouseButtonEvent&);
			void handleMouseRelease(const sf::Event::MouseButtonEvent&);
			void handleMouseMove(	const sf::Event::MouseMoveEvent&);
			void handleMouseScroll(	const sf::Event::MouseWheelScrollEvent&);
		};
		
	}
}

