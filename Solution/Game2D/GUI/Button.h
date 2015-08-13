#pragma once

#include "Control.h"
#include "..\GAME2D_API.h"
#include "..\ResourceManager.h"

#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>

#include <memory>
#include <functional>
#include <string>
#include <map>

namespace Game2D {
	namespace GUI {

		class GAME2D_API Button : public Control {
			// ABSTRACT DATA TYPES
		public:
			typedef std::shared_ptr<Button> Ptr;
			typedef std::function<void()> Callback;
			enum class State {
				Pressed,
				Selected,
				Unselected,
				Disabled,
			};
			typedef ResourceManager<sf::Texture, State> TextureManager;

			// ENCAPSUALTED FIELDS
		private:
			Callback _callback;
			std::map<State, sf::Texture*> _textures;
			sf::Sprite _sprite;
			sf::Text _text;
			bool _isToggle;

			// INTERFACE
		public:
			Button(const sf::Font&, const TextureManager&);
			void setCallback(Callback);
			void setText(const std::string&);
			void setToggle(bool flag);
			virtual bool isSelectable() const;
			virtual void select();
			virtual void unselect();
			virtual void activate();
			virtual void deactivate();
			virtual void enable();
			virtual void disable();
			virtual void handleEvent(const sf::Event&);

			// HELPER FUNCTIONS
		private:
			virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
			
		};
		
	}
}
