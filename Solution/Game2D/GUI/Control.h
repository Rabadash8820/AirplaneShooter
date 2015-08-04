#pragma once

#include "..\GAME2D_API.h"

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\System\NonCopyable.hpp>
#include <SFML\Window\Event.hpp>

#include <memory>

namespace Game2D {
	namespace GUI {

		class GAME2D_API Control :
			public sf::Drawable,
			public sf::Transformable,
			public sf::NonCopyable
		{
			// ABSTRACT DATA TYPES
		public:
			typedef std::shared_ptr<Control> Ptr;

			// ENCAPSULATED FIELDS
		private:
			bool _isEnabled;
			bool _isSelected;
			bool _isActive;

			// INTERFACE
		public:
			Control();
			virtual ~Control();
			virtual bool isSelectable() const = 0;
			bool isEnabled() const;
			virtual void enable();
			virtual void disable();
			bool isSelected() const;
			virtual void select();
			virtual void unselect();
			virtual bool isActive() const;
			virtual void activate();
			virtual void deactivate();
			virtual void handleEvent(const sf::Event&) = 0;

		};

	}
}
