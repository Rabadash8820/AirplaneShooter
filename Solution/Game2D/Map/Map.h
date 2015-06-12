#pragma once

#include "../GAME2D_API.h"
#include "../Render/SceneNode.h"
#include "../Render/Entity.h"
#include "../Input/Categories.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

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
		std::unique_ptr<Categories> _categories;
		Entity* _player;
		sf::Vector2f _playerSpawn;
		std::queue<Command> _commands;

		// INTERFACE
	public:
		Map(sf::RenderWindow*, sf::FloatRect, size_t, std::unique_ptr<Categories>);
		void build();
		virtual void handleEvent(const sf::Event&) = 0;
		virtual void handleRealtimeInput() = 0;
		void update(sf::Time);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		~Map();

		// HELPER FUNCTIONS
	protected:
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;
		virtual void updateCurrent(sf::Time dt) = 0;

	};
	
}