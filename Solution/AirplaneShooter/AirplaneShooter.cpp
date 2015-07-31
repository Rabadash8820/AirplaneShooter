#include "AirplaneShooter.h"
#include "DesertMap.h"
#include "Aircraft.h"
#include "Categories.h"
#include "States\States.h"
#include "States\TitleState.h"
#include "States\MenuState.h"
#include "States\GameState.h"
#include "States\PauseState.h"
#include "ResourceIds\Fonts.h"
#include "ResourceIds\Textures.h"

#include <Input\Command.h>
#include <Input\KeyBinding.h>
#include <Utility.h>

#include <memory>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

AirplaneShooter::AirplaneShooter() :
	Application(VideoMode(640, 480), "Airplane Shooter")
{
	_window.setKeyRepeatEnabled(false);
	
	// Load game-wide resources
	string currDir    = Utility::currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string fontDir    = currDir + "\\Resources\\Fonts\\";
	_textures.load(Textures::TitleScreen, textureDir + "TitleScreen.png");
	_fonts.load(Fonts::Main, fontDir + "Sansation.ttf");

	// Initialize the statistics text
	_statisticsText.setFont(_fonts[Fonts::Main]);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10u);

	// Register states and start in the Title state
	registerStates();
	_stateManager.push(States::Title);
}

void AirplaneShooter::registerStates() {
	_stateManager.registerState<TitleState>(States::Title);
	_stateManager.registerState<MenuState>(States::Menu);
	_stateManager.registerState<GameState>(States::Game);
	_stateManager.registerState<PauseState>(States::Pause);
}
