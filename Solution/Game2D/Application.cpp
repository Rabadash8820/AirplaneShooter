#include "Application.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
Application::Application(VideoMode videoMode, string title, Time frameDur) :
	_window(videoMode, title),
	_frameDuration(frameDur),
	_stateManager(State::Context(_window, _textures, _fonts)),
	_statisticsNumFrames(0) 
{
	_window.setKeyRepeatEnabled(false);

	//_fonts.load(Fonts::Main, "Media/Sansation.ttf");
	//_textures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	//_statisticsText.setFont(_fonts[Fonts::Main]);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10u);

	registerStates();
	//_stateManager.push(States::Title);
}
void Application::run() {
	// Main game loop
	Clock clock;
	Time timeSinceUpdate = Time::Zero;
	while (_window.isOpen()) {

		// Process events and update as many as times as needed
		Time dt = clock.restart();
		timeSinceUpdate += dt;
		while (timeSinceUpdate > _frameDuration) {
			this->processInput();
			this->update(_frameDuration);
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
	_window.clear();
	_stateManager.draw();

	_window.setView(_window.getDefaultView());
	_window.draw(_statisticsText);

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
