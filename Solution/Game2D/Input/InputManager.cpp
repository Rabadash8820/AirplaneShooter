#include "InputManager.h"

#include <cassert>

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
void InputManager::handleEvent(const Event& e, queue<Command>& commands) const {
	switch (e.type) {
		// Handle keyboard events
	case Event::KeyPressed:
		handleKeyPress(e.key, commands);
		break;
	case Event::KeyReleased:
		handleKeyRelease(e.key, commands);
		break;

		// Handle mouse events
	case Event::MouseButtonPressed:
		handleMousePress(e.mouseButton, commands);
		break;
	case Event::MouseButtonReleased:
		handleMouseRelease(e.mouseButton, commands);
		break;
	case Event::MouseMoved:
		handleMouseMove(e.mouseMove, commands);
		break;
	case Event::MouseWheelScrolled:
		handleMouseScroll(e.mouseWheelScroll, commands);
		break;

		// Handle joystick events
	case Event::JoystickButtonPressed:
		handleJoystickPress(e.joystickButton, commands);
		break;
	case Event::JoystickButtonReleased:
		handleJoystickRelease(e.joystickButton, commands);
		break;
	case Event::JoystickConnected:
		handleJoystickConnect(e.joystickConnect, commands);
		break;
	case Event::JoystickDisconnected:
		handleJoystickDisconnect(e.joystickConnect, commands);
		break;
	case Event::JoystickMoved:
		handleJoystickMove(e.joystickMove, commands);
		break;

		// Handle everything else
	default:
		handleOtherEvent(e, commands);
		break;
	}
}
void InputManager::handleRealtimeInput(queue<Command>& commands) const {
	handleRealtimeKeyboard(commands);
	handleRealtimeMouse(commands);
	handleRealtimeJoystick(commands);
	handleOtherRealtime(commands);
}
void InputManager::handleRealtimeKeyboard(queue<Command>& commands) const {
	// Loop through each KeyBinding to see if any of those Keys are pressed
	for (auto& binding : _keyBindings) {
		for (auto& key : binding.second) {

			// If so, then add the associated Command to the queue
			if (Keyboard::isKeyPressed(key)) {
				auto& it = _commandBindings.find(binding.first);
				//assert(it != _commandBindings.end());
				commands.push(it->second);
			}

		}
	}
}
set<Keyboard::Key> InputManager::keysBoundTo(ActionId action) const {
	auto it = _keyBindings.find(action);
	return (it == _keyBindings.end()) ?
		set<Keyboard::Key>() :
		it->second;
}
void InputManager::bindKey(Keyboard::Key key, ActionId action) {
	// Unbind this Key from all other ActionIds
	for (auto& binding : _keyBindings) {
		set<Keyboard::Key> boundKeys = binding.second;
		if (binding.first != action && boundKeys.find(key) != boundKeys.end())
			binding.second.erase(key);
	}

	// Bind the Key to the provided ActionId
	_keyBindings[action].insert(key);
}

// HELPER FUNCTIONS
void InputManager::bindCommand(const Command& command, ActionId action) {
	// Bind the Command to the provided ActionId (make sure that id wasn't already used)
	assert(_commandBindings.find(action) == _commandBindings.end());
	_commandBindings.insert(make_pair(action, command));
}
