#include "SettingsState.h"

#include "..\Player.h"
#include "..\ResourceIds\Textures.h"
#include "..\ResourceIds\Fonts.h"

#include <Utility.h>

using namespace Shooter;
using namespace Game2D;
using namespace Game2D::GUI;
using namespace std;
using namespace sf;

// INTERFACE
SettingsState::SettingsState(StateManager& manager, Context context) :
	State(manager, context),
	_background(context.textures->get(Textures::TitleScreen))
{
	// Pack Controls for each Command defined by the Player class into the GUI container
	Player& player = *reinterpret_cast<Player*>(getContext().inputManager);
	vector<CommandId> commands = player.commands();
	for (size_t c = 0; c < commands.size(); ++c) {
		CommandId id = commands[c];
		packControl(id, 100.f + 50 * c, player.boundCommand(id).name, context);
	}
	updateLabels();

	// Pack a 'Reset Defaults' button into the GUI container
	auto reset = make_shared<Button>(context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	reset->setPosition(80.f, 325.f);
	reset->setText("Reset");
	reset->setTexture(Button::State::Selected, Textures::ButtonSelected);
	reset->setTexture(Button::State::Pressed,  Textures::ButtonPressed);
	reset->setCallback([this]() {
		getContext().inputManager->resetDefaults();
		updateLabels();
	});
	_guiContainer.pack(reset);

	// Pack a 'Back to Main Menu' button into the GUI container
	auto goBack = make_shared<Button>(context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	goBack->setPosition(80.f, 375.f);
	goBack->setText("Back");
	goBack->setTexture(Button::State::Selected, Textures::ButtonSelected);
	goBack->setTexture(Button::State::Pressed,  Textures::ButtonPressed);
	goBack->setCallback(bind(
		&SettingsState::requestPopState, this));
	_guiContainer.pack(goBack);
}
bool SettingsState::handleEvent(const sf::Event& e) {
	// Let the GUI handle anything but a Key release
	if (e.type != Event::KeyReleased)
		_guiContainer.handleEvent(e);

	// Determine if we are in "binding Key mode"
	bool binding = false;
	Player& player = *reinterpret_cast<Player*>(getContext().inputManager);
	vector<CommandId> commands = player.commands();
	CommandId selectedId;
	for (size_t c = 0; c < commands.size(); ++c) {
		CommandId id = commands[c];
		if (_bindingButtons[id]->isActive()) {
			binding = true;
			selectedId = id;
			break;
		}
	}

	// If we are, then bind this Key to the selected Command
	if (binding) {
		player.bindKey(e.key.code, selectedId);
		_bindingButtons[selectedId]->deactivate();
		updateLabels();
	}
	else
		_guiContainer.handleEvent(e);

	// Don't allow other States to handle this Event
	return false;
}
bool SettingsState::update(sf::Time dt) {
	// Allow other States to update
	return true;
}
void SettingsState::draw() {
	RenderWindow& window = *getContext().window;

	window.draw(_background);
	window.draw(_guiContainer);
}

// HELPER FUNCTIONS
void SettingsState::packControl(CommandId id, float y, const std::string& buttonText, Context context) {
	_bindingButtons[id] = make_shared<Button>(context.fonts->get(Fonts::Main), *context.textures, Textures::ButtonUnselected);
	Button& button = *_bindingButtons[id];
	button.setPosition(80.f, y);
	button.setText(buttonText);
	button.setToggle(true);
	button.setTexture(Button::State::Selected, Textures::ButtonSelected);
	button.setTexture(Button::State::Pressed,  Textures::ButtonPressed);

	_bindingLabels[id] = make_shared<Label>("", context.fonts->get(Fonts::Main));
	Label& label = *_bindingLabels[id];
	label.setPosition(300.f, 15.f + y);

	_guiContainer.pack(_bindingButtons[id]);
	_guiContainer.pack(_bindingLabels[id]);
}
void SettingsState::updateLabels() {
	Player& player = *reinterpret_cast<Player*>(getContext().inputManager);

	for (CommandId id : player.commands())
		updateLabel(id, player.boundKeys(id));
}
void SettingsState::updateLabel(CommandId id, set<Keyboard::Key> keys) {
	// Create a comma-delimited list of the Keys bound to this Command
	size_t numKeys = keys.size();
	string text = "";
	auto key = keys.begin();
	if (numKeys == 0)
		text = "--";
	else {
		text = Utility::toString(*key);
		for (++key; key != keys.end(); ++key)
			text += (", " + Utility::toString(*key));
	}

	// Set the text of this Command's Label to that string
	_bindingLabels[id]->setText(text);
}
