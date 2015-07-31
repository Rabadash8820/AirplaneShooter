#include "AirplaneShooter.h"
#include "DesertMap.h"
#include "Aircraft.h"
#include "Categories.h"
#include "States\States.h"
#include "States\TitleState.h"
#include "ResourceIds\Fonts.h"
#include <Input\Command.h>
#include <Input\KeyBinding.h>
#include <memory>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

AirplaneShooter::AirplaneShooter() :
	Application(VideoMode(640, 480), "Airplane Shooter")
{
	_window.setKeyRepeatEnabled(false);
	
	// Get resource directories
	string currDir    = currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string shaderDir  = currDir + "\\Resources\\Shaders\\";
	string soundDir   = currDir + "\\Resources\\Sounds\\";
	string fontDir    = currDir + "\\Resources\\Fonts\\";

	// Load textures
	_textures.load(Textures::Desert,	  textureDir + "Desert.png");
	_textures.load(Textures::Eagle,		  textureDir + "Eagle.png");
	_textures.load(Textures::Raptor,	  textureDir + "Raptor.png");
	_textures.load(Textures::TitleScreen, textureDir + "TitleScreen.png");

	// Load fonts
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
}