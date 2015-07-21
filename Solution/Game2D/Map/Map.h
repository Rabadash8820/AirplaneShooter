#pragma once

#include "../GAME2D_API.h"
#include "../Render/SceneNode.h"
#include "../Render/Entity.h"
#include "../Input/Command.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>

// Define a general macro to get the current working directory
#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

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
		Entity* _player;
		sf::Vector2f _playerSpawn;
		std::queue<Command> _commands;

		// INTERFACE
	public:
		Map(sf::RenderWindow*, sf::FloatRect, size_t);
		void build();
		void pushCommand(Command);
		void update(sf::Time);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

		// HELPER FUNCTIONS
	protected:
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;
		virtual void handleEvent(const sf::Event&);
		void updateOnCommands(sf::Time);
		virtual void updateCurrent(sf::Time dt) = 0;
		std::string projectDirectory();

	};
	
}
