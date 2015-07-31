#pragma once

#include "..\GAME2D_API.h"
#include "StateId.h"
#include "..\Render\ResourceManager.h"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\System\Time.hpp>

#include <memory>

namespace Game2D {

	class StateManager;

	class GAME2D_API State {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<State> Ptr;
		struct Context {
			sf::RenderWindow* window;
			TextureManager* textures;
			FontManager* fonts;
			Context(sf::RenderWindow&, TextureManager&, FontManager&);
		};

		// PRIVATE VARIABLES / CONSTANTS
	private:
		StateManager* _manager;
		Context _context;

		// INTERFACE
	public:
		State(StateManager&, Context);
		virtual ~State();
		virtual void draw() = 0;
		virtual bool update(sf::Time) = 0;
		virtual bool handleEvent(const sf::Event&) = 0;

		// HELPER FUNCTIONS
	protected:
		void requestPush(StateId);
		void requestPop();
		void requestClear();
		Context getContext() const;
		void centerOrigin(sf::Sprite&);
		void centerOrigin(sf::Text&);

	};

}
