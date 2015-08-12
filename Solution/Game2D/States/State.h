#pragma once

#include "..\GAME2D_API.h"
#include "Context.h"
#include "..\Render\ResourceManager.h"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include <memory>

namespace Game2D {

	class StateManager;
	class InputManager;

	class GAME2D_API State {
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<State> Ptr;

		// PRIVATE FIELDS
	private:
		StateManager* _manager;
		Context _context;

		// INTERFACE
	public:
		State(StateManager&);
		virtual ~State();
		virtual void draw() = 0;
		virtual bool update(sf::Time) = 0;
		virtual bool handleEvent(const sf::Event&) = 0;

		// HELPER FUNCTIONS
	protected:
		template<typename StateClass>
		void requestPushState() {
			_manager->push<StateClass>();
		}
		void requestPopState();
		void requestClearStates();
		Context getContext() const;

	};

}
