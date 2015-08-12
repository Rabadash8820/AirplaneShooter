#pragma once

#include "GAME2D_API.h"
#include "States\StateManager.h"
#include "States\Context.h"

#include <SFML\System\Time.hpp>

#include <string>
#include <memory>

namespace Game2D {

	class GAME2D_API Application {
		// PRIVATE VARIABLES / CONSTANTS		
	protected:
		Context _context;
		sf::Time _frameDuration;
		StateManager _stateManager;

		// INTERFACE
	public:
		Application(Context, sf::Time = sf::seconds(1.f / 60.f));
		void run();

		// HELPER FUNCTIONS
	protected:
		virtual void updateCurrent(sf::Time);
		virtual void drawCurrent();
		virtual void registerStates() = 0;
	private:
		void processInput();
		void update(sf::Time);
		void draw();
	};

}
