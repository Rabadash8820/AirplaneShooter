#pragma once

#include "../GAME2D_API.h"
#include "../Render/ResourceManager.h"
#include "../Render/SceneNode.h"
#include "../Render/Entity.h"
#include "../Input/Categories.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

namespace Shooter {

	class Map :
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
		Game2D::TextureManager _textures;
		Game2D::SoundManager _sounds;
		Game2D::FontManager _fonts;
		Game2D::ShaderManager _shaders;
		Game2D::SceneNode _sceneTree;
		size_t _numLayers;
		std::vector<Game2D::SceneNode*> _sceneLayers;
		Game2D::Entity* _player;
		sf::Vector2f _playerSpawn;
		std::queue<Game2D::Command> _commands;

		// INTERFACE
	public:
		Map(sf::RenderWindow*, sf::FloatRect, size_t);
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
		void updateOnCommands(sf::Time);
		virtual void updateCurrent(sf::Time dt) = 0;

	};
	
}
