#pragma once

#include "..\GAME2D_API.h"
#include "..\Input\Command.h"

#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Time.hpp>

#include <memory>
#include <vector>

namespace Game2D {

	class GAME2D_API SceneNode : public sf::Transformable,
								 public sf::Drawable,
								 public sf::NonCopyable
	{
		// VARIABLES
	public:
		typedef std::unique_ptr<SceneNode> Ptr;
	private:
		SceneNode* _parent;
		std::vector<Ptr> _children;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		SceneNode();

		// INTERFACE FUNCTIONS
	public:
		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);
		Ptr detachChild(SceneNode* node);
		sf::Vector2f getWorldPosition() const;
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		void update(sf::Time);
		virtual Category getCategory() const;
		void onCommand(const Command&, sf::Time);
		
		// HELPER FUNCTIONS
	private:
		void drawChildren(sf::RenderTarget&, sf::RenderStates) const;
		void updateChildren(sf::Time);
	protected:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time);

	};

}
