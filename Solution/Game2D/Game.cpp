#include "Game.h"

using namespace sf;
using namespace std;
using namespace Game2D;

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
				this->processInput();
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
	void Game::processInput() {
		Event e;
		while (_window.pollEvent(e))
			handleEvent(e);

		handleRealtimeInput();
	}
	void Game::handleEvent(const Event& e) {
		// Toggle Paused state
			switch (e.type) {
			case Event::GainedFocus:
				_paused = false;
				break;
			case Event::LostFocus:
				_paused = true;
				break;

		// Close the game window
			case Event::Closed:
				_window.close();
				break;
			}
	}
	void Game::handleRealtimeInput() {
		// Push keyboard events to the current Map's queue
		for (auto& binding : _keyBindings) {
			if (Keyboard::isKeyPressed(binding.key))
				_map->pushEvent(binding.getCommand());
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
