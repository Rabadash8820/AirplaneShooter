#pragma once

#include <States\State.h>
#include <States\StateManager.h>
#include <States\ParallelTask.h>

#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>

namespace Shooter {

	class LoadingState : public Game2D::State {
		// ENCAPSULATED FIELDS
	private:
		sf::Text _loadingText;
		sf::RectangleShape _progressBarBkgrd;
		sf::RectangleShape _progressBar;
		Game2D::ParallelTask* _loadingTask;
		const float BAR_OFFSET = 10.f;

		// INTERFACE
	public:
		LoadingState(Game2D::StateManager&);
		virtual bool handleEvent(const sf::Event&);
		virtual bool update(sf::Time);
		virtual void draw();

		// HELPER FUNCTIONS
	private:
		void setProgress(float);
	};

}
