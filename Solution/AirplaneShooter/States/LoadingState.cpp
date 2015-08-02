#include "LoadingState.h"

#include "..\ResourceIds\Fonts.h"
#include "States.h"

#include <Utility.h>

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>

using namespace Shooter;
using namespace Game2D;
using namespace sf;

// INTERFACE
LoadingState::LoadingState(StateManager& manager, Context context) :
	State(manager, context),
	_loadingText("Loading Resources", (*context.fonts)[Fonts::Main])
{
	// Initialize the loading text
	RenderWindow& window = *getContext().window;
	Utility::centerOrigin(_loadingText);
	_loadingText.setPosition(window.getSize().x / 2u, window.getSize().y / 2u + 50);

	// Initialize progress bar background rectangle
	_progressBarBkgrd.setFillColor(Color::White);
	_progressBarBkgrd.setSize(Vector2f(window.getSize().x - 2 * BAR_OFFSET, 10));
	_progressBarBkgrd.setPosition(BAR_OFFSET, _loadingText.getPosition().y + 40);


	// Initialize rectangle of the progress bar itself
	_progressBar.setFillColor(Color(100, 100, 100));
	_progressBar.setSize(Vector2f(200, 10));
	_progressBar.setPosition(BAR_OFFSET, _loadingText.getPosition().y + 40);

	// Begin loading in parallel, starting the progress bar at 0%
	setProgress(0.f);
	_loadingTask.execute();
}
bool LoadingState::handleEvent(const Event& e) {
	// Allow other States to handle this Event
	return true;
}
bool LoadingState::update(Time dt) {
	// If loading is done then push the Game state
	if (_loadingTask.isFinished()) {
		requestPopState();
		requestPushState(States::Game);
	}

	// Otherwise, update the progress bar's percent based on the loading task's progress
	else
		setProgress(_loadingTask.getProgress());

	// Allow other States to update
	return true;
}
void LoadingState::draw() {
	sf::RenderWindow& window = *getContext().window;
	window.draw(_loadingText);
	window.draw(_progressBarBkgrd);
	window.draw(_progressBar);
}

// HELPER FUNCTIONS
void LoadingState::setProgress(float percent) {
	// Restrict progress to 100%
	if (percent > 100.f)
		percent = 100.f;

	// Incease the width of the progress bar
	Vector2f bkgrdSize = _progressBarBkgrd.getSize();
	_progressBar.setSize(Vector2f(bkgrdSize.x * percent, bkgrdSize.y));
}
