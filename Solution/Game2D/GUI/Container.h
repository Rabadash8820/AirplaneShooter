#pragma once

#include "Component.h"

#include <SFML\Window\Event.hpp>

#include <memory>
#include <vector>

namespace Game2D {
	namespace GUI {

		class Container : public Component {
			// ABSTRACT DATA TYPES
		public:
			typedef std::shared_ptr<Container> Ptr;

			// ENCAPSULATED FIELDS
		private:
			std::vector<Component::Ptr> _children;
			int _selectedChild;

			// INTERFACE
		public:
			Container();
			void pack(Component::Ptr component);
			virtual bool isSelectable() const;
			virtual void handleEvent(const sf::Event&);

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

