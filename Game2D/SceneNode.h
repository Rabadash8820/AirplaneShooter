#pragma once

#include "GAME2D_API.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace Game2D {

	class GAME2D_API SceneNode : public sf::Transformable,
					  public sf::Drawable,
					  public sf::NonCopyable {
	public:
		// TYPES
		typedef std::unique_ptr<SceneNode> Ptr;

	private:
		// VARIABLES
		SceneNode* _parent;
		std::vector<Ptr> _children;

	public:
		// CONSTRUCTORS / DESTRUCTOR
		SceneNode();
		~SceneNode();

		// INTERFACE FUNCTIONS
		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);
		virtual void update(sf::Time);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
		sf::Vector2f getWorldPosition() const;

	private:
		// HELPER FUNCTIONS
		virtual void updateCurrent(sf::Time);
		void updateChildren(sf::Time);
		virtual void renderCurrent(sf::RenderTarget&, sf::RenderStates) const;
		void renderChildren(sf::RenderTarget&, sf::RenderStates) const;

	};

}