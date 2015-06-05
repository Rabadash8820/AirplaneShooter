#pragma once

#include "GAME2D_API.h"
#include "ResourceHolderTypes.h"
#include "SceneNode.h"
#include "Entity.h"
#include <vector>

namespace Game2D {

	class GAME2D_API Map : public sf::NonCopyable {
	protected:
		// VARIABLES / CONSTANTS
		sf::RenderWindow& _window;
		sf::View _view;
		Game2D::SceneNode _sceneGraph;
		std::vector<SceneNode*> _sceneLayers;
		Game2D::Entity* _player;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		explicit Map(sf::RenderWindow&, size_t);
		~Map();

		// INTERFACE FUNCTIONS
		void update(sf::Time);
		void render();

	private:
		// HELPER FUNCTIONS
		virtual void baseUpdates(sf::Time dt) {}
		virtual void loadResources() {}
		virtual void buildScene() {}

	};

}