#include "Game.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	Game::Game(sf::VideoMode videoMode, std::string title, sf::Time frameDuration) :
		_frameDuration(frameDuration),
		_window(videoMode, title)
	{

	}
	Game::~Game() { }

	// INTERFACE FUNCTIONS
	void Game::run() {
		// Build the map
		_map->build();

		// Main game loop
		sf::Clock clock;
		sf::Time timeSinceUpdate = sf::seconds(0.f);
		while (_window.isOpen()) {
			
			// Process events and update as many as times as needed
			timeSinceUpdate += clock.restart();
			while (timeSinceUpdate > _frameDuration) {
				this->processEvents();
				this->update(_frameDuration);
				timeSinceUpdate -= _frameDuration;
			}

			// Render graphics in the game window
			this->draw();
		}
	}

	// HELPER FUNCTIONS
	void Game::setMap(Map::Ptr map) {
		Map* oldMap = _map.release();
		delete oldMap;
		_map = std::move(map);
	}
	void Game::processEvents() {
		// Process all events in the window's queue
		sf::Event e;
		while (_window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:	// Handle the window-closed event
				_window.close();
			}
		}
	}
	void Game::update(sf::Time dt) {
		_map->update(dt);
	}
	void Game::draw() {
		_window.clear();
		_window.draw(*_map);
		_window.display();
	}

}