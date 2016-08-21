#pragma once

#include "../GAME2D_API.h"
#include "../Render/ResourceManager.h"
#include "../Render/SceneNode.h"
#include "../Render/Entity.h"
#include "../Input/Categories.h"
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
		TextureManager _textures;
		SoundManager _sounds;
		FontManager _fonts;
		ShaderManager _shaders;
		SceneNode _sceneTree;
		size_t _numLayers;
		std::vector<SceneNode*> _sceneLayers;
		Entity* _player;
		sf::Vector2f _playerSpawn;
		std::queue<Command> _commands;

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
		std::string projectDirectory();

	};
	
}
