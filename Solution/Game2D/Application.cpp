#include "Application.h"

#include <SFML\System\Clock.hpp>
#include <SFML\Window\Event.hpp>

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Application::Application(VideoMode videoMode, string title, InputManager* input, Time frameDur) :
	_window(videoMode, title),
	_frameDuration(frameDur),
	_inputManager(input),
	_stateManager(State::Context(_window, _textures, _fonts, *input)),
	_statisticsNumFrames(0)
{ }
void Application::run() {
	// Main game loop
	Clock clock;
	Time timeSinceUpdate = Time::Zero;
	while (_window.isOpen()) {

		// Process events and update as many as times as needed
		// If the State stack is empty, close the Window
		// Check inside this loop, because 
		Time dt = clock.restart();
		timeSinceUpdate += dt;
		while (timeSinceUpdate > _frameDuration) {
			this->processInput();
			this->update(_frameDuration);
			
			if (_stateManager.isEmpty())
				_window.close();

			timeSinceUpdate -= _frameDuration;
		}

		// Draw graphics in the game window
		this->updateStatistics(dt);
		this->draw();
	}
}

// HELPER FUNCTIONS
void Application::processInput() {
	Event e;
	while (_window.pollEvent(e)) {
		// Pass all Events to the StateManager
		_stateManager.handleEvent(e);

		// Handle the closed Event
		if (e.type == Event::Closed)
			_window.close();
	}
}
void Application::update(Time dt) {
	_stateManager.update(dt);
}
void Application::draw() {
	// Clear the window and draw graphics
	_window.clear();
	_stateManager.draw();

	// Draw statistics text (not affected by View)
	_window.setView(_window.getDefaultView());
	_window.draw(_statisticsText);

	// Display all drawn objects in the window
	_window.display();
}
void Application::updateStatistics(Time dt) {
	_statisticsUpdateTime += dt;
	_statisticsNumFrames += 1;
	if (_statisticsUpdateTime >= sf::seconds(1.0f)) {
		_statisticsText.setString("FPS: " + to_string(_statisticsNumFrames));

		_statisticsUpdateTime -= sf::seconds(1.0f);
		_statisticsNumFrames = 0;
	}
}
void Application::registerStates() {

}
