#include "SettingsState.h"

#include "..\Player.h"

using namespace Shooter;
using namespace Game2D;
using namespace std;
using namespace sf;

// INTERFACE
SettingsState::SettingsState(StateManager& manager, Context context) :
	State(manager, context)
{ }
bool SettingsState::handleEvent(const sf::Event& e) {
	return false;
}
bool SettingsState::update(sf::Time dt) {
	return false;
}
void SettingsState::draw() {

}

// HELPER FUNCTIONS
void SettingsState::updateLabels() {
	Player& player = *reinterpret_cast<Player*>(getContext().inputManager);

}
void SettingsState::addButtonLabel(float y, const std::string& text, Context context) {

}

