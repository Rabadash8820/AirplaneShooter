#include "Application.h"

#include <SFML\System\Clock.hpp>
#include <SFML\Window\Event.hpp>

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Application::Application(unique_ptr<Context> context, Time frameDur) :
	_context(move(context)),
	_frameDuration(frameDur),
	_stateManager(_context.get())
{ }
void Application::run() {
	// Main game loop
	Clock clock;
	Time timeSinceUpdate = Time::Zero;
	RenderWindow& window = *_context->window;
	while (window.isOpen()) {

		// Process events and update as many as times as needed
		// If the State stack is empty, close the Window
		// Check inside this loop, because 
		Time dt = clock.restart();
		timeSinceUpdate += dt;
		while (timeSinceUpdate > _frameDuration) {
			this->processInput();
			this->update(_frameDuration);
			
			if (_stateManager.isEmpty())
				window.close();

			timeSinceUpdate -= _frameDuration;
		}

		// Draw graphics in the game window
		this->draw();
	}
}

// HELPER FUNCTIONS
void Application::processInput() {
	Event e;
	RenderWindow& window = *_context->window;
	while (window.pollEvent(e)) {
		// Pass all Events to the StateManager
		_stateManager.handleEvent(e);

		// Handle the closed Event
		if (e.type == Event::Closed)
			window.close();
	}
}
void Application::update(Time dt) {
	updateCurrent(dt);
	_stateManager.update(dt);
}
void Application::updateCurrent(Time dt) { }
void Application::draw() {
	// Clear the window and draw graphics
	RenderWindow& window = *_context->window;
	window.clear();

	_stateManager.draw();
	drawCurrent();
	
	window.display();
}
void Application::drawCurrent() { }
