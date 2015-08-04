#include "AirplaneShooter.h"

#include "States\States.h"
#include "States\TitleState.h"
#include "States\MenuState.h"
#include "States\GameState.h"
#include "States\PauseState.h"
#include "States\LoadingState.h"
#include "ResourceIds\Fonts.h"
#include "ResourceIds\Textures.h"
#include "Player.h"

#include <Utility.h>

#include <string>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

AirplaneShooter::AirplaneShooter() :
	Application(VideoMode(640, 480), "Airplane Shooter", new Player())
{
	_window.setKeyRepeatEnabled(false);
	
	// Get resource folders
	string currDir    = Utility::currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string fontDir    = currDir + "\\Resources\\Fonts\\";

	// Load resources used by entire application
	_fonts.load(Fonts::Main, fontDir + "Sansation.ttf");
	_textures.load(Textures::TitleScreen,	   textureDir + "TitleScreen.png");
	_textures.load(Textures::ButtonUnselected, textureDir + "ButtonNormal.png");
	_textures.load(Textures::ButtonSelected,   textureDir + "ButtonSelected.png");
	_textures.load(Textures::ButtonPressed,    textureDir + "ButtonPressed.png");

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
	_stateManager.registerState<MenuState>(States::MainMenu);
	_stateManager.registerState<GameState>(States::Game);
	_stateManager.registerState<PauseState>(States::Pause);
	_stateManager.registerState<LoadingState>(States::Loading);
}
