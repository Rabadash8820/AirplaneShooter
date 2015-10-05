#pragma once

#include "../GAME2D_API.h"
#include "../Input/Command.h"
#include "../Input/Categories.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <set>
#include <queue>

namespace Game2D {

	class GAME2D_API SceneNode : public sf::Transformable,
								 public sf::Drawable,
								 public sf::NonCopyable
	{
		// ABSTRACT DATA TYPES
	public:
		typedef std::unique_ptr<SceneNode> Ptr;
		typedef std::pair<SceneNode*, SceneNode*> Pair;

		// ENCAPSUALTED FIELDS
	private:
		SceneNode* _parent;
		std::vector<Ptr> _children;
		Category _category;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		SceneNode();
		SceneNode(Category);
		virtual ~SceneNode();

		// INTERFACE FUNCTIONS
	public:
		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);
		Ptr detachChild(SceneNode* node);

		sf::Vector2f getWorldPosition() const;
		sf::Transform getWorldTransform() const;
		virtual sf::FloatRect getBoundingRect() const;

		static void checkSceneCollision(const SceneNode&, std::set<Pair>&);

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;
		void update(sf::Time);
		virtual unsigned int getCategory() const;
		void giveCommand(const Command&, sf::Time);
		
		// HELPER FUNCTIONS
	private:
		void drawChildren(sf::RenderTarget&, sf::RenderStates) const;
		void drawBoundingRect(sf::RenderTarget&, sf::RenderStates) const;
		void checkNodeCollision(SceneNode&, std::set<Pair>&) const;
		void updateChildren(sf::Time, std::queue<Command>&);
	protected:
		virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
		virtual void updateCurrent(sf::Time, std::queue<Command>&);

	};

}
