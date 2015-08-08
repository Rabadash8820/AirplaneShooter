#pragma once

#include <Render\ResourceManager.h>
#include <Render\SceneNode.h>
#include <Render\Entity.h>
#include <Input\Command.h>

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\View.hpp>
#include <SFML\Graphics\Rect.hpp>

#include <memory>
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
		std::queue<Game2D::Command>& getCommandQueue();
		void update(sf::Time);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

		// HELPER FUNCTIONS
	protected:
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;
		void updateOnCommands(sf::Time);
		virtual void updateCurrent(sf::Time dt) = 0;

	};
	
}
