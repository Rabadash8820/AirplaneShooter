#pragma once

#include "StateId.h"
#include "Render\ResourceManager.h"
#include <SFML\Graphics.hpp>
#include <memory>

namespace Game2D {

	class StateManager;

	class State {
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

	};

}
