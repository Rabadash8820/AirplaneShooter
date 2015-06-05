#pragma once

#include "GAME2D_API.h"
#include "ResourceManager.h"
#include "SceneNode.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Game2D {

	class GAME2D_API Map :
		public sf::NonCopyable,
		public sf::Drawable
	{
		// VARIABLES / CONSTANTS
	protected:
		sf::View _view;
		sf::FloatRect _worldBounds;
		Game2D::SceneNode _sceneTree;
		size_t _numLayers;
		std::vector<SceneNode*> _sceneLayers;
		Game2D::Entity* _player;
		sf::Vector2f _playerSpawn;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Map(sf::View, sf::FloatRect, size_t);
		~Map();

		// INTERFACE FUNCTIONS
	public:
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		void update(sf::Time);

		// HELPER FUNCTIONS
	private:
		void initialize();
	protected:
		virtual void baseUpdate(sf::Time dt) = 0;
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;

	};

}