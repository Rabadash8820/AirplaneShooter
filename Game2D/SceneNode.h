#pragma once

#include "GAME2D_API.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace Game2D {

	class GAME2D_API SceneNode : public sf::Transformable,
								 public sf::Drawable,
								 public sf::NonCopyable
	{
	public:
		// TYPES
		typedef std::unique_ptr<SceneNode> NodePtr;

	private:
		// VARIABLES
		SceneNode* _parent;
		std::vector<NodePtr> _children;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		SceneNode();
		~SceneNode();

		// INTERFACE FUNCTIONS
		void attachChild(NodePtr child);
		NodePtr detachChild(const SceneNode& node);
		NodePtr detachChild(SceneNode* node);
		sf::Vector2f getWorldPosition() const;
		virtual void update(sf::Time);

	private:
		// HELPER FUNCTIONS
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		void drawChildren(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time);
		void updateChildren(sf::Time);

	};

}