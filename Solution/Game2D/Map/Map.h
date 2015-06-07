#pragma once

#include "../GAME2D_API.h"
#include "../Render/SceneNode.h"
#include "../Render/Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Game2D {

	class GAME2D_API Map :
		public sf::NonCopyable,
		public sf::Drawable
	{
		// VARIABLES / CONSTANTS
	public:
		typedef std::unique_ptr<Map> Ptr;
	protected:
		sf::RenderWindow* _window;
		sf::View _view;
		sf::IntRect _worldBounds;
		Game2D::SceneNode _sceneTree;
		size_t _numLayers;
		std::vector<SceneNode*> _sceneLayers;
		Game2D::Entity* _player;
		sf::Vector2f _playerSpawn;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		Map(sf::RenderWindow*, sf::FloatRect, size_t);
		~Map();

		// INTERFACE FUNCTIONS
	public:
		void build();
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		void update(sf::Time);

		// HELPER FUNCTIONS
	protected:
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;
		virtual void updateCurrent(sf::Time dt) = 0;

	};
	
}