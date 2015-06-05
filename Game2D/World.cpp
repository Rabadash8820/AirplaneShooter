#include "World.h"
#include "Brush.h"

namespace Game2D {

	// CONSTRUCTORS / DESTRUCTOR
	World::World(sf::RenderWindow& w) :
		_window(w),
		_view(_window.getDefaultView()),
		_playerSpawn(_worldBounds.width / 2.f,
					 _worldBounds.height - _view.getSize().y / 2.f),
		_player()
	{
		loadTextures();
		buildScence();
	}
	World::~World() {}

	// INTERFACE FUNCTIONS
	void World::update(sf::Time dt) {
		// Update the other scene nodes
		_sceneTree.update(dt);
	}
	void World::render() {
		_window.draw(_sceneTree);
	}

	// HELPER FUNCTIONS
	void World::loadTextures() { }
	void World::buildScence() {
		// Set the window's View
		_view.setCenter(_playerSpawn);
		_window.setView(_view);
	}

}