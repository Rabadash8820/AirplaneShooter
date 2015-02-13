#include "Game.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Game::Game(std::string title) :
		_window(sf::VideoMode(480, 640), title) {

	}
	Game::~Game() {}

	// FUNCTIONS
	void Game::run() {
		sf::Clock clock;
		sf::Time timeSinceUpdate = sf::seconds(0.f);

		// Main game loop
		while (_window.isOpen()) {
			
			// Process events and update as many as times as needed
			timeSinceUpdate += clock.restart();
			while (timeSinceUpdate > FRAME_DURATION) {
				processEvents(FRAME_DURATION);
				update();
				timeSinceUpdate -= FRAME_DURATION;
			}

			// Render graphics in the game window
			render();
		}
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
	void Game::render() {

	}

}