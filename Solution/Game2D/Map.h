#pragma once

#include "GAME2D_API.h"
#include "Render\ResourceManager.h"
#include "Render\SceneNode.h"
#include "Input\Command.h"

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include <memory>
#include <vector>
#include <queue>

namespace Game2D {

	class GAME2D_API Map :
		public sf::NonCopyable,
		public sf::Drawable
	{
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<Map> Ptr;

		// ENCAPSULATED FIELDS
	protected:
		sf::RenderWindow& _window;
		TextureManager _textures;
		SoundManager _sounds;
		FontManager _fonts;
		ShaderManager _shaders;
		SceneNode _sceneTree;
		std::queue<Command> _commands;

		// INTERFACE
	public:
		Map(sf::RenderWindow&);
		void build();
		std::queue<Command>& getCommandQueue();
		void update(sf::Time);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

		// HELPER FUNCTIONS
	protected:
		virtual void loadResources() = 0;
		virtual void buildScene() = 0;
		void updateOnCommands(sf::Time);
		virtual void updateCurrent(sf::Time dt) = 0;
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const = 0;

	};
	
}
