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

		// CONSTRUCTORS / DESTRUCTOR
	public:
		SceneNode();
		~SceneNode();

		// INTERFACE FUNCTIONS
	public:
		void attachChild(NodePtr child);
		NodePtr detachChild(const SceneNode& node);
		NodePtr detachChild(SceneNode* node);
		sf::Vector2f getWorldPosition() const;
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		void update(sf::Time);
		
		// HELPER FUNCTIONS
	private:
		void drawChildren(sf::RenderTarget&, sf::RenderStates) const;
		void updateChildren(sf::Time);
	protected:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time);

	};

}