#include "InputManager.h"

#include "..\GUI\Container.h"

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
	for (auto binding : _keyBindings) {
		for (auto key : binding.second) {

			// If so, then add the associated Command to the queue
			if (isRealtime(binding.first) && Keyboard::isKeyPressed(key)) {
				auto it = _commandBindings.find(binding.first);
				//assert(it != _commandBindings.end());
				commands.push(it->second);
			}

		}
	}
}
void InputManager::bindKey(Keyboard::Key key, CommandId id) {
	// Don't bind Keys that are reserved for the GUI
	if (key == GUI::Container::activationKey)
		return;

	// Unbind this Key from all other Ids
	for (auto binding : _keyBindings) {
		set<Keyboard::Key> boundKeys = binding.second;
		if (binding.first != id && boundKeys.find(key) != boundKeys.end())
			_keyBindings[binding.first].erase(key);
	}

	// Bind the Key to the provided Id
	_keyBindings[id].insert(key);
}
set<Keyboard::Key> InputManager::boundKeys(CommandId id) const {
	auto it = _keyBindings.find(id);
	return (it == _keyBindings.end()) ?
		set<Keyboard::Key>() :
		it->second;
}
Command InputManager::boundCommand(CommandId id) const {
	auto it = _commandBindings.find(id);
	assert(it != _commandBindings.end());
	return it->second;
}
void InputManager::resetDefaults() {
	_keyBindings.clear();

	// Reset all key bindings to the defaults
	for (auto binding : _defaultKeyBindings) {
		for (Keyboard::Key k : binding.second)
			_keyBindings[binding.first].insert(k);
	}
}


// HELPER FUNCTIONS
void InputManager::bindDefaultKey(Keyboard::Key key, CommandId id) {
	// Assert that there are no default Key collisions
	for (auto binding : _defaultKeyBindings) {
		set<Keyboard::Key> boundKeys = binding.second;
		assert(boundKeys.find(key) == boundKeys.end());
	}

	// Bind the Key to the provided Id
	_defaultKeyBindings[id].insert(key);

	// Also initialize the current KeyBinding to this default
	bindKey(key, id);
}
void InputManager::bindCommand(const Command& command, CommandId id) {
	// Bind the Command to the provided Id (make sure that id wasn't already used)
	assert(_commandBindings.find(id) == _commandBindings.end());
	_commandBindings.insert(make_pair(id, command));
}

void InputManager::handleKeyPress(const Event::KeyEvent& key, queue<Command>& commands) const {
	// Check if this key is bound to any Command
	for (auto binding : _keyBindings) {

		// If so, then add the associated Command to the queue
		CommandId c = binding.first;
		set<Keyboard::Key> boundKeys = binding.second;
		if (!isRealtime(c) && boundKeys.find(key.code) != boundKeys.end())
			commands.push(_commandBindings.at(c));

	}
}
