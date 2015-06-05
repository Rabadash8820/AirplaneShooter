#include "Game.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Game::Game(sf::Time frameDuration, sf::VideoMode videoMode, std::string title) :
		_frameDuration(frameDuration),
		_window(videoMode, title)
	{

	}
	Game::~Game() { }

	// INTERFACE FUNCTIONS
	void Game::run() {
		sf::Clock clock;
		sf::Time timeSinceUpdate = sf::seconds(0.f);

		// Main game loop
		while (_window.isOpen()) {
			
			// Process events and update as many as times as needed
			timeSinceUpdate += clock.restart();
			while (timeSinceUpdate > _frameDuration) {
				processEvents(_frameDuration);
				update();
				timeSinceUpdate -= _frameDuration;
			}

			// Render graphics in the game window
			draw();
		}
	}

	// HELPER FUNCTIONS
	void Game::setMap(MapPtr map) {
		_map.release();
		_map = std::move(map);
	}
	void Game::processEvents(sf::Time dt) {
		// Process all events in the queue
		sf::Event e;
		while (_window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:	// Handle the window-closed event
				_window.close();
			}
		}
	}
	void Game::update() {

	}
	void Game::draw() {

	}

}