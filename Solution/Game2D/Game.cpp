#include "Game.h"

using namespace sf;
using namespace std;

namespace Game2D {
	
	// CONSTRUCTORS / DESTRUCTOR
	Game::Game(VideoMode videoMode, string title, Time frameDuration) :
		_frameDuration(frameDuration),
		_window(videoMode, title),
		_paused(false)
	{

	}
	Game::~Game() { }

	// INTERFACE FUNCTIONS
	void Game::run() {
		// Build the map
		_map->build();

		// Main game loop
		Clock clock;
		Time timeSinceUpdate = seconds(0.f);
		while (_window.isOpen()) {
			
			// Process events and update as many as times as needed
			timeSinceUpdate += clock.restart();
			while (timeSinceUpdate > _frameDuration) {
				this->processEvents();
				if (!_paused)
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
		Event e;
		while (_window.pollEvent(e)) {
			switch (e.type) {
			case Event::GainedFocus:
				_paused = false;
				break;
			case Event::LostFocus:
				_paused = true;
				break;
			case Event::Closed:
				_window.close();
				break;
			}
		}
	}
	void Game::update(Time dt) {
		_map->update(dt);
	}
	void Game::draw() {
		_window.clear();
		_window.draw(*_map);
		_window.display();
	}

}