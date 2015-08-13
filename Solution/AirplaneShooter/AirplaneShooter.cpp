#include "AirplaneShooter.h"

#include "States\Context.h"
#include "States\TitleState.h"
#include "Player.h"

#include <GUI\Button.h>
#include <States\Context.h>
#include <Utility.h>

#include <string>

using namespace Shooter;
using namespace Game2D;
using namespace Game2D::GUI;
using namespace sf;
using namespace std;

AirplaneShooter::AirplaneShooter() :
	_window(VideoMode(640, 480), "Airplane Shooter", Style::Close),
	Application(move(unique_ptr<Context>(
		new Context(_window, _buttonTextures, _textures, _fonts, _player)))),
	_statisticsNumFrames(0)
{
	_window.setKeyRepeatEnabled(false);
	
	// Get resource folders
	string currDir    = Utility::currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string fontDir    = currDir + "\\Resources\\Fonts\\";

	// Load resources used by entire application
	_fonts.load(FontId::Main, fontDir + "Sansation.ttf");
	_textures.load(TextureId::TitleScreen,			textureDir + "TitleScreen.png");
	_buttonTextures.load(Button::State::Unselected, textureDir + "ButtonNormal.png");
	_buttonTextures.load(Button::State::Selected,   textureDir + "ButtonSelected.png");
	_buttonTextures.load(Button::State::Pressed,	textureDir + "ButtonPressed.png");
	_buttonTextures.load(Button::State::Disabled,	textureDir + "ButtonDisabled.png");

	// Initialize the statistics text
	_statisticsText.setFont(_fonts[FontId::Main]);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10u);

	// Start in the Title state
	_stateManager.push<TitleState>();
}

void AirplaneShooter::updateCurrent(Time dt) {
	// Update the statistics text
	_statisticsUpdateTime += dt;
	_statisticsNumFrames += 1;
	if (_statisticsUpdateTime >= seconds(1.0f)) {
		_statisticsText.setString("FPS: " + to_string(_statisticsNumFrames));

		_statisticsUpdateTime -= seconds(1.0f);
		_statisticsNumFrames = 0;
	}
}
void AirplaneShooter::drawCurrent() {
	// Draw statistics text
	RenderWindow& window = *_context->window;
	window.setView(window.getDefaultView());
	window.draw(_statisticsText);
}
